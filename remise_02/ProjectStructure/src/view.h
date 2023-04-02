#ifndef VIEW_H
#define VIEW_H

#include "model/direction.h"
#include "model/gameobject.h"
#include <string>

class View {
public:
    virtual void displayTitle() = 0;

    virtual void displayBoard(const std::vector<GameObject>& elements) = 0;

    virtual void displayError(std::string message) = 0;

    virtual Direction askDir() = 0;
    };

#endif // VIEW_H
