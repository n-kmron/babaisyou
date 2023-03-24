#include "levelloader.h"
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

static map<string, Element> elemConversion_;

LevelLoader::LevelLoader(const int & numLevel) : numLevel_ { numLevel-1 } {
    fileAllLines();
    elemConversion_ = {
        {"text_baba", Element::TEXT_BABA},
        {"text_wall", Element::TEXT_WALL},
        {"text_rock", Element::TEXT_ROCK},
        {"text_lava", Element::TEXT_LAVA},
        {"text_grass", Element::TEXT_GRASS},
        {"text_metal", Element::TEXT_METAL},
        {"text_goop", Element::TEXT_GOOP},
        {"text_flag", Element::TEXT_FLAG},
        {"is", Element::IS},
        {"you", Element::YOU},
        {"win", Element::WIN},
        {"stop", Element::STOP},
        {"sink", Element::SINK},
        {"push", Element::PUSH},
        {"kill", Element::KILL},
        {"baba", Element::BABA},
        {"wall", Element::WALL},
        {"rock", Element::ROCK},
        {"lava", Element::LAVA},
        {"grass", Element::GRASS},
        {"metal", Element::METAL},
        {"goop", Element::GOOP},
        {"flag", Element::FLAG}
    };
}

void LevelLoader::fileAllLines() {
    // Ouvrir le fichier

    stringstream ss;
    ss << "level" << numLevel_ << ".txt";
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


/**
 * @brief conversionElementByString retrouve le littéral correspondant à l'énum Element à partir d'un string
 * @param elem l'élément à chercher
 * @return l'élément sous forme d'enum
 */
Element static conversionElementByString(const string & elem) {
    return elemConversion_.at(elem);
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
            GameObject finalElem(conversionElementByString(type), pos);
            elements.push_back(finalElem);
    }
    return elements;
}
