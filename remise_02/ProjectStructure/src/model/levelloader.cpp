#include "levelloader.h"
#include "element.h"
#include "../util.cpp"
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

LevelLoader::LevelLoader(const unsigned int & numLevel) : numLevel_ { numLevel-1 } {
    fileAllLines();
}

void LevelLoader::fileAllLines() {
    // Ouvrir le fichier

    stringstream ss;
    ss << "level_" << numLevel_ << ".txt";
    string filename = ss.str();
    std::ifstream level(filename);

    // Vérifier si l'ouverture a réussi
    if (!level.is_open()) {
        throw std::ifstream::failure("Impossible d'ouvrir le fichier.");
    }

    // Lire le contenu du fichier et placer chaque ligne dans un vector
    std::string fileLine;
    while (std::getline(level, fileLine)) {
        this->fileAllLines_.push_back(fileLine);
    }

    // Fermer le fichier
    level.close();
}


vector<GameObject> LevelLoader::createLevel() {
    //Vector servant pour le constructeur d'un LevelMechanics
    vector<GameObject> elements;

    for(int i=0; i<fileAllLines_.size(); ++i) {
        std::vector<string> splittedElem; //vector contenant chaque mot du string
        string line { fileAllLines_.at(i) };
        stringstream ss(line);
            string elementPart;
            while (ss >> elementPart) {
                splittedElem.push_back(elementPart);
            }
            if(splittedElem.size() != 3) {
                throw std::invalid_argument("Le fichier n'est pas bien configuré");
            }
            //récupérer le type de notre élément
            string type { splittedElem[0] };
            // Convertir les deux derniers mots en entiers
            int posCol = stoi(splittedElem[1]); //la colonne de la postion est le deuxième mot de la découpe
            int posRow = stoi(splittedElem[2]); //la colonne de la postion est le troisième mot de la découpe

            Position pos(posRow, posCol);
            GameObject finalElem(conversionElementFromText(type), pos);
            elements.push_back(finalElem);
    }
    return elements;
}
