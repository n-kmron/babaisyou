#include <iostream>
#include <regex>
#include <string>
#include "controller.h"
#include "model/game.h"
#include "model/gameobject.h"
#include "model/observer.h"
#include "view.h"
#include "util.cpp"
#include <unistd.h>
#include <vector>

using namespace std;

class TextView : public View, Observer {

private:
    std::unique_ptr<Game> game_;
    Controller controller_;

public:

    TextView() : game_ { std::make_unique<Game>() }, controller_ { Controller(*game_) }{
        game_->registerObserver(this);
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
                    vector<Element> elems = findElementAtPosition(game_->elements(), pos);
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
        cout << "You are going now to the next level : Level " << game_->level() << endl;
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
        if(!game_->isWon()) {
            //controller_.playShot(askDir());
            if(game_->isLost()) {
                displayKilled();
                if(askRestart()) {
                    game_->restart();
                } else {
                    exit(0);
                }
            }
        } else {
            displayWon();
            if(game_->level() < 5) {
                displayNextLevel();
                game_->nextLevel();
            } else {
                exit(0);
            }
        }
    }
};

