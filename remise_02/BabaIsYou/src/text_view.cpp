#include <iostream>
#include <regex>
#include <string>
#include "text_view.h"
#include "util.cpp"
#include <unistd.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <limits>

using namespace std;

/**
 * @brief check if the save is safe and allows it or not
 */
void TextView::checkSave(string name) {
    stringstream ss;
    ss << "levels/saves/" << name << ".txt";
    string location = ss.str();
    ifstream infile(location);

    if(infile.good()) {
        cout << "This save already exists, do you want to replace it ?" << endl;
        string input;
        bool validInput = false;

        while (!validInput)
        {
            cout << "Enter yes or no: ";
            cin >> input;

            if (input == "yes")
            {
                controller_.saveGame(location);
                validInput = true;
            }
            else if (input == "no")
            {
                validInput = true;
            }
            else
            {
                cout << "Invalid input. ";
            }
        }
    } else {
        controller_.saveGame(location);
    }
}


TextView::TextView() : controller_ { Controller(this) }{
}

void TextView::launch() {
    displayTitle();
    controller_.chooseLevel(askWhichLevel());
    controller_.start();
}

void TextView::displayTitle() {
    cout << "==========Welcome to Baba Is You ==========" << endl << endl;
}

void TextView::displayBoard() {
    for(unsigned int height=0; height<controller_.levelSize().first+1; ++height) {
        cout << endl;
        for(unsigned int width=0; width<controller_.levelSize().second+1; ++width) {
            if(height==0 || height== (controller_.levelSize().first))
                cout << "-";
            else if(width==0 || width == (controller_.levelSize().second))
                cout << "|";
            else {
                Position pos(height, width);
                vector<Element> elems = findElementAtPosition(controller_.elements(), pos);
                if(!elems.empty()) {
                    cout << elemConversionFromElement(elems.at(elems.size()-1));
                } else {
                    cout << " ";
                }
            }
        }
    }
    cout << endl;
}

void TextView::displayWon(){
    cout << "Congratulation, You won !" << endl;
}

void TextView::displayNextLevel() {
    cout << "You are going now to the next level : Level " << controller_.level()+1 << endl;
}

void TextView::displayKilled() {
    cout << "Sorry, you are dead !" << endl;
}

void TextView::displayError(string message) {
    cout << "Error : " << message << " !" << endl;
}

unsigned int TextView::displayUserSaves() {
    filesystem::path path_to_saves("levels/saves");
    unsigned int numberSaves { 0 };

    cout << "Your saves : " << endl;
    for (const auto& entry : filesystem::directory_iterator(path_to_saves))
    {
        if (entry.is_regular_file())
        {
            string filename { entry.path().filename().string() };
            // Remove the double quotes if they exist.
            if (filename.front() == '"' && filename.back() == '"') {
                filename = filename.substr(1, filename.size() - 2);
            }

            // Remove the file extension.
            size_t extension_pos = filename.rfind('.');
            if (extension_pos != std::string::npos) {
                filename = filename.substr(0, extension_pos);
            }

            if(filename.size() != 0) {
                cout << filename << endl;
                numberSaves++;
            }
        }
    }
    return numberSaves;
}

string TextView::askWhichLevel() {
    regex regex("^[SN]$");
    string input;
    while (true) {
        cout << ">>Do you want to load a save (S) or start a new game (N) : ";
        cin >> input;
        if (regex_match(input, regex)) {
            if(input == "S") {
                unsigned int nbSaves = displayUserSaves();
                if(nbSaves < 1) {
                    cout << "You don't have any saves" << endl;
                    cout << "Level 1 loading..." << endl;
                    return "level_1";
                }
                else {
                    string name;
                    cout << ">> Please choice your save : ";
                    cin >> name;
                    stringstream ss;
                    ss << "saves/" << name;
                    string filename = ss.str();
                    return filename;
                }
            }
            if(input == "N") {
                return "level_1";
            }
        } else {
            cout << "Invalid input. Please try again.\n";
        }
    }
}

string TextView::askDir() {
    regex regex("^[ZQSDR]$");
    string input;
    while (true) {
        cout << ">>Enter a direction (ZQSD) or R to restart: " << endl;
        cin >> input;
        if (regex_match(input, regex)) {
            return input;
        } else {
            cout << "Invalid direction. Please try again.\n";
        }
    }
}

bool TextView::askRestart() {
    regex regex("^[RS]$");
    string input;
    while (true) {
        cout << ">>PRESS R TO RESTART (OR S TO STOP): " << endl;
        cin >> input;
        if (regex_match(input, regex)) {
            if(input == "R") {
                return true;
            }
            if(input == "S") {
                return false;
            }
        } else {
            cout << "Invalid input. Please try again.\n";
        }
    }
}

void TextView::askSave() {
    string input;
    cout << ">>PRESS S TO SAVE THE GAME AND QUIT (OR ENTER TO CONTINUE) : " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);
    if(input == "S") {
        string name;
        cout << ">>GIVE A NAME FOR YOUR SAVE : ";
        cin >> name;
        checkSave(name);
    }
}


void TextView::update() {
    displayBoard();

    if(controller_.isLost()) {
        displayKilled();
        if(askRestart()) {
            controller_.restart();
        } else {
            exit(0);
        }
    }

    if(!controller_.isWon()) {
        controller_.playShot(askDir());
    }

    else {
        displayWon();
        if(controller_.level() < 5) {
            displayNextLevel();
            controller_.nextLevel();
            askSave();
            controller_.start();
        } else {
            exit(0);
        }
    }
}

