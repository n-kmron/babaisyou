#include "levelloader.h"
#include "element.h"
#include "../util.cpp"
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

LevelLoader::LevelLoader(const string & fileLevel) : fileLevel_ { fileLevel }, numLevel_ { 0 } {
    readAllLines();
}

void LevelLoader::readAllLines() {

    // open file
    stringstream ss;
    ss << "levels/" << fileLevel_ << ".txt";
    string filename = ss.str();
    ifstream level(filename);

    // check the opening
    if (!level.is_open()) {
        cerr << "This game does not exist, sorry !" << endl;
        exit(0);
    }

    // read the number of the level
    string numLevelAsString;
    getline(level, numLevelAsString);
    numLevel_ = stoi(numLevelAsString);
    if(numLevel_ < 1 || numLevel_ > 5) {
        throw invalid_argument("the level number is not correct");
    }

    // read file and add each line in a vector
    string fileLine;
    while (getline(level, fileLine)) {
        this->fileAllLines_.push_back(fileLine);
    }

    // close file
    level.close();
}


vector<GameObject> LevelLoader::createLevel() {
    vector<GameObject> elements;

    for(int i=0; i<fileAllLines_.size(); ++i) {
        vector<string> splittedElem;
        string line { fileAllLines_.at(i) };
        stringstream ss(line);
            string elementPart;
            while (ss >> elementPart) {
                splittedElem.push_back(elementPart);
            }
            if(splittedElem.size() != 3) {
                throw invalid_argument("the file is not well configured");
            }
            string type { splittedElem[0] };
            int posCol = stoi(splittedElem[1]); //row is the second part of the splitted element
            int posRow = stoi(splittedElem[2]); //col is the third part of the splitted element

            Position pos(posRow, posCol);
            GameObject finalElem(conversionElementFromText(type), pos);
            elements.push_back(finalElem);
    }
    return elements;
}

unsigned int LevelLoader::numLevel() {
    return numLevel_;
}

