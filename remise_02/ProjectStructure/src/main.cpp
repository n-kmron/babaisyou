#include <iostream>
#include <string>

using namespace std;

int main()
{
    //concatenate the string and the int
    stringstream sstm;

    sstm << ":/levels/level_0.txt" ;
    string filename = sstm.str();

    QFile file(filename); // chemin vers le fichier .txt dans le fichier QRC
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return 1; // Si le fichier ne peut pas être ouvert, sortez de la fonction

        // Le fichier est ouvert avec succès
        QTextStream in(&file);
        QString content = in.readAll(); // Lire tout le contenu du fichier en une seule fois
        file.close();
        std::cout << content.toStdString() << std::endl;


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
