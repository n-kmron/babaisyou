#include <iostream>
#include <regex>
#include <string>
#include "textview.h"
#include "../util.cpp"
#include <unistd.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <limits>


using namespace std;



vector<vector<Element>> TextView::getPositionsMap(const pair<unsigned int, unsigned int> & sizes, const vector<GameObject> & elements) {
    vector<vector<Element>> positionsMap(sizes.first, vector<Element>(sizes.second));
    for(unsigned int i=0; i<elements.size(); ++i) {
        GameObject current = elements.at(i);
        unsigned int row = current.pos().row();
        unsigned int col = current.pos().col();
        Element elem = current.element();
        if(positionsMap.at(row).at(col) != Element::NULLELEMENT) {
            if(Util::getZIndexOfElement(elem) > Util::getZIndexOfElement(positionsMap.at(row).at(col))) {
                positionsMap.at(row).at(col) = elem;
            }
        } else {
            positionsMap.at(row).at(col) = elem;
        }
    }

    return positionsMap;
}


TextView::TextView() {
}

void TextView::displayTitle() {
    cout << "==========Welcome to Baba Is You ==========" << endl << endl;
}

void TextView::displayBoard(const pair<unsigned int, unsigned int> & sizes, const vector<GameObject> & elements) {
    vector<vector<Element>> positionsMap = getPositionsMap(sizes, elements);

    for(unsigned int height=0; height<sizes.first; ++height) {
        cout << endl;
        for(unsigned int width=0; width<sizes.second; ++width) {
            if(positionsMap.size() >= height && positionsMap.at(height).size() >= width) {
                cout << Util::elemConversionFromElement(positionsMap.at(height).at(width));
            }
        }
    }
    cout << endl;
}

void TextView::displayWon(){
    cout << "Congratulation, You won !" << endl;
}

void TextView::displayNextLevel(unsigned int actualLevel) {
    cout << "You are going now to the next level : Level " << actualLevel+1 << endl;
}

void TextView::displayKilled() {
    cout << "Sorry, you are dead !" << endl;
}

void TextView::displayError(std::string message) {
    cerr << message << endl;
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

bool TextView::overwriteSave() {
    displayError("This save already exists, do you want to replace it ?");
    string input;
    while (true)
    {
        cout << "Enter yes or no: ";
        cin >> input;

        if (input == "yes")
        {
            return true;
        }
        else if (input == "no")
        {
            return false;
        }
        else
        {
            cout << "Invalid input. ";
        }
    }
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
            displayError("Invalid input. Please try again");
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
            displayError("Invalid input. Please try again");
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
            displayError("Invalid input. Please try again");
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
    }
}


void TextView::update(pair<unsigned int, unsigned int> sizes, vector<GameObject> elements) {
    displayBoard(sizes, elements);
}

