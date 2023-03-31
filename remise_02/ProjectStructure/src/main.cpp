#include "model/levelloader.h"
#include "text_view.cpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdbool.h>
#include <vector>
#include <map>


using namespace std;




int main()
{
    LevelLoader level(1);
    TextView view;
    view.displayTitle();
    view.displayMap(level.createLevel());
}
