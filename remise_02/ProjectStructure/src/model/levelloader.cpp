#include "levelloader.h"
#include "element.h"
#include "../util.cpp"
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

LevelLoader::LevelLoader(const unsigned int & numLevel) : numLevel_ { numLevel-1 } {
    readAllLines();
}

void LevelLoader::readAllLines() {

    // open file
    stringstream ss;
    ss << "level_" << numLevel_ << ".txt";
    string filename = ss.str();
    std::ifstream level(filename);

    // check the opening
    if (!level.is_open()) {
        throw std::ifstream::failure("Impossible d'ouvrir le fichier.");
    }

    // read file and add each line in a vector
    std::string fileLine;
    while (std::getline(level, fileLine)) {
        this->fileAllLines_.push_back(fileLine);
    }

    // close file
    level.close();
}


vector<GameObject> LevelLoader::createLevel() {
    vector<GameObject> elements;

    for(int i=0; i<fileAllLines_.size(); ++i) {
        std::vector<string> splittedElem;
        string line { fileAllLines_.at(i) };
        stringstream ss(line);
            string elementPart;
            while (ss >> elementPart) {
                splittedElem.push_back(elementPart);
            }
            if(splittedElem.size() != 3) {
                throw std::invalid_argument("the file is not well configured");
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
