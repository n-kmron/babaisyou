#include "levelloader.h"
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

LevelMechanics LevelLoader::createLevel() {

    //concatenate the string and the int
    stringstream sstm;
    sstm << "resources/levels/empty_levels/level_" << this->numLevel << ".txt";
    string filename = sstm.str();

    //read the file
    fstream readLevel(filename, ios::in);
    if(readLevel.is_open()) {
        string line;
        while(getline(readLevel, line)) {
            cout << line << endl;
        }
        cout << "Fin de la lecture des données du fichier" << endl;
        readLevel.close();
    } else {
        cout << "erreur lors de l'ouverture" << endl;
    }
}

