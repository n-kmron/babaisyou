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

    TextView() : controller_ { Controller() }{
        controller_.registerAsObserver(this);
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
        cout << "Congratulation, You won !";
    }

    void displayNextLevel() override {
        cout << "You are going now to the next level : Level " << controller_.level() << endl;
    }

    void displayKilled() override{
        cout << "Sorry, you are dead !";
    }

    void displayError(string message) override {
        cout << "Error : " << message << " !" << endl;
    }

    Direction askDir() override {
        std::regex regex("^[ZQSD]$");
        std::string input;
        while (true) {
            cout << ">>Enter a direction (ZQSD): " << endl;
            std::cin >> input;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::regex_match(input, regex)) {
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
                std::cout << "Invalid direction. Please try again.\n";
            }
        }
    }

    bool askRestart() override {
        std::regex regex("^[RS]$");
        std::string input;
        while (true) {
            cout << ">>PRESS R TO RESTART (OR S TO STOP): " << endl;
            std::cin >> input;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::regex_match(input, regex)) {
                if(input == "R") {
                    return true;
                }
                if(input == "S") {
                    return false;
                }
            } else {
                std::cout << "Invalid input. Please try again.\n";
            }
        }
    }

    void update() override {
        displayBoard();
        if(!controller_.isWon()) {
            //controller_.playShot(askDir());
            if(controller_.isLost()) {
                displayKilled();
                if(askRestart()) {
                    controller_.restart();
                } else {
                    exit(0);
                }
            }
        } else {
            displayWon();
            if(controller_.level() < 5) {
                displayNextLevel();
                controller_.nextLevel();
            } else {
                exit(0);
            }
        }
    }
};

