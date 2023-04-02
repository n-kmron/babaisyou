#include <iostream>
#include "model/gameobject.h"
#include "view.h"
#include "util.cpp"
#include <vector>

using namespace std;

class TextView : public View {
public:

    void displayTitle() override {
        cout << "Welcome to Baba Is You !" << std::endl;
    }

    void displayBoard(const vector<GameObject>& elements) override {
        for(int height=0; height<18; ++height) {
            cout << endl;
            for(int width=0; width<18; ++width) {
                if(height==0 || height==17)
                    cout << "-";
                else if(width==0 || width == 17)
                    cout << "|";
                else {
                    Position pos(height, width);
                    vector<Element> elems = findElementAtPosition(elements, pos);
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

    void displayError(string message) override {
        cout << "Error : " << message << " !" << endl;
    }

    Direction askDir() override {
        //faire une regex pour la direction
        cout << ">>Entrez une direction : " << endl;
        return Direction::UP;
    }


};

