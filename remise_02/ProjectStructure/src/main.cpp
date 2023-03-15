#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdbool.h>
#include <vector>
#include <map>
#include "model/position.h"
#include "model/element.h"
#include "model/gameobject.h"

using namespace std;


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


int main()
{

    // Ouvrir le fichier
        std::ifstream level("level_0.txt");

        // Vérifier si l'ouverture a réussi
        if (!level.is_open()) {
            std::cout << "Erreur : Impossible d'ouvrir le fichier\n";
            return 1;
        }

        std::vector<string> fileAllLines;
        // Lire le contenu du fichier et placer chaque ligne dans un vector
        std::string fileLine;
        while (std::getline(level, fileLine)) {
            cout << fileLine << endl;
            fileAllLines.push_back(fileLine);
        }

        // Fermer le fichier
        level.close();

        //Vector servant pour le constructeur d'un LevelMechanics
        vector<GameObject> elements;

        for(int i=0; i<fileAllLines.size(); ++i) {
            std::vector<string> splittedElem; //vector contenant chaque mot du string
            string line { fileAllLines.at(i) };
            stringstream ss(line);
                string elementPart;
                while (ss >> elementPart) {
                    splittedElem.push_back(elementPart);
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

        //A la fin de ma boucle, le vector de GameObject 'elements' est complet



}
