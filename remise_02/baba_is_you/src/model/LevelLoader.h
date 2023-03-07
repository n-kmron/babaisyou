#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include "levelmechanics.h"

class LevelLoader
{
    private:
        int numLevel;

    public:
       inline LevelLoader(const int & numLevel);

       inline LevelMechanics createLevel();

};

#endif // LEVELLOADER_H
