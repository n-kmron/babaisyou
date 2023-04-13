#include <iostream>
#include <regex>
#include <string>
#include "controller.h"
#include "model/gameobject.h"
#include "model/observer.h"
#include "view.h"
#include "util.cpp"
#include <unistd.h>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class TextView : public View, Observer {

private:
    Controller controller_;

    /**
     * @brief check if the save is safe and allows it or not
     */
    void checkSave(string name) {
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

public:

    TextView() : controller_ { Controller(this) }{
    }

    void launch() override {
        controller_.registerAsObserver();
        displayTitle();
        controller_.putLevel(askWhichLevel());
        controller_.start();
    }

    void displayTitle() override {
        cout << "==========Welcome to Baba Is You ==========" << endl << endl;
    }

    void displayBoard() override {
        for(int height=0; height<18; ++height) {
            cout << endl;
            for(int width=0; width<18; ++width) {
                if(height==0 || height==17)
                    cout << "-";
                else if(width==0 || width == 17)
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

    void displayWon() override{
        cout << "Congratulation, You won !" << endl;
    }

    void displayNextLevel() override {
        cout << "You are going now to the next level : Level " << controller_.level()+1 << endl;
    }

    void displayKilled() override{
        cout << "Sorry, you are dead !" << endl;
    }

    void displayError(string message) override {
        cout << "Error : " << message << " !" << endl;
    }

    unsigned int displayUserSaves() override {
        filesystem::path path_to_saves("levels/saves");
        unsigned int numberSaves { 0 };

        cout << "Your saves : " << endl;
        for (const auto& entry : filesystem::directory_iterator(path_to_saves))
        {
            if (entry.is_regular_file())
            {
                string filename { entry.path().filename() };
                // Remove the double quotes if they exist.
                if (filename.front() == '"' && filename.back() == '"') {
                    filename = filename.substr(1, filename.size() - 2);
                }

                // Remove the file extension.
                size_t extension_pos = filename.rfind('.');
                if (extension_pos != std::string::npos) {
                    filename = filename.substr(0, extension_pos);
                }
                cout << filename << endl;
            }
            numberSaves++;
        }
        return numberSaves;
    }

    string askWhichLevel() override {
        regex regex("^[SN]$");
        string input;
        while (true) {
            cout << ">>Do you want to load a save (S) or start a new game (N) : ";
            cin >> input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (regex_match(input, regex)) {
                if(input == "S") {
                    unsigned int nbSaves = displayUserSaves();
                    if(nbSaves <= 1) {
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

    Direction askDir() override {
        regex regex("^[ZQSD]$");
        string input;
        while (true) {
            cout << ">>Enter a direction (ZQSD): " << endl;
            cin >> input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (regex_match(input, regex)) {
                if(input == "Z") {
                    return Direction::UP;
                }
                if(input == "Q") {
                    return Direction::LEFT;
                }
                if(input == "S") {
                    return Direction::DOWN;
                }
                if(input == "D") {
                    return Direction::RIGHT;
                }
            } else {
                cout << "Invalid direction. Please try again.\n";
            }
        }
    }

    bool askRestart() override {
        regex regex("^[RS]$");
        string input;
        while (true) {
            cout << ">>PRESS R TO RESTART (OR S TO STOP): " << endl;
            cin >> input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    void askSave() override {
        string input;
        cout << ">>PRESS S TO SAVE THE GAME AND QUIT (OR ENTER TO CONTINUE) : " << endl;
        getline(cin, input);
        if(input == "S") {
            cout << ">>GIVE A NAME FOR YOUR SAVE : ";
            string name;
            cin >> name;
            checkSave(name);
        }
    }


    void update() override {
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
                controller_.registerAsObserver();
            } else {
                exit(0);
            }
        }
    }
};

