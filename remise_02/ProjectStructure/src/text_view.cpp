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

using namespace std;

class TextView : public View, Observer {

private:
    Controller controller_;

public:

    TextView() : controller_ { Controller(this) }{
        controller_.registerAsObserver();
        displayTitle();
        controller_.start();
    }

    void displayTitle() override {
        cout << "Welcome to Baba Is You !" << endl;
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
            controller_.saveGame(name);
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
        } else {
            displayWon();
            askSave();
            if(controller_.level() < 5) {
                displayNextLevel();
                controller_.nextLevel();
            } else {
                exit(0);
            }
        }
    }
};

