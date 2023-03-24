#include "levelloader.h"
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;


LevelLoader::LevelLoader(const int & numLevel) : numLevel_ { numLevel-1 } {
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


/**
 * @brief conversionElementByString retrouve le littéral correspondant à l'énum Element à partir d'un string
 * @param elem l'élément à chercher
 * @return l'élément sous forme d'enum
 */
Element static conversionElementByString(const string & elem) {
    map<string, Element> elemConversion;
    elemConversion.insert(std::make_pair("text_baba", Element::TEXT_BABA));
    elemConversion.insert(std::make_pair("text_wall", Element::TEXT_WALL));
    elemConversion.insert(std::make_pair("text_rock", Element::TEXT_ROCK));
    elemConversion.insert(std::make_pair("text_lava", Element::TEXT_LAVA));
    elemConversion.insert(std::make_pair("text_grass", Element::TEXT_GRASS));
    elemConversion.insert(std::make_pair("text_metal", Element::TEXT_METAL));
    elemConversion.insert(std::make_pair("text_goop", Element::TEXT_GOOP));
    elemConversion.insert(std::make_pair("text_flag", Element::TEXT_FLAG));
    elemConversion.insert(std::make_pair("is", Element::IS));
    elemConversion.insert(std::make_pair("you", Element::YOU));
    elemConversion.insert(std::make_pair("win", Element::WIN));
    elemConversion.insert(std::make_pair("stop", Element::STOP));
    elemConversion.insert(std::make_pair("sink", Element::SINK));
    elemConversion.insert(std::make_pair("push", Element::PUSH));
    elemConversion.insert(std::make_pair("kill", Element::KILL));
    elemConversion.insert(std::make_pair("baba", Element::BABA));
    elemConversion.insert(std::make_pair("wall", Element::WALL));
    elemConversion.insert(std::make_pair("rock", Element::ROCK));
    elemConversion.insert(std::make_pair("lava", Element::LAVA));
    elemConversion.insert(std::make_pair("grass", Element::GRASS));
    elemConversion.insert(std::make_pair("metal", Element::METAL));
    elemConversion.insert(std::make_pair("goop", Element::GOOP));
    elemConversion.insert(std::make_pair("flag", Element::FLAG));

    return elemConversion.at(elem);
}


LevelMechanics LevelLoader::createLevel() {
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
    return LevelMechanics(elements);
}

