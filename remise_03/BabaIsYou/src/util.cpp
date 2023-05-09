#include "model/element.h"
#include "model/gameobject.h"
#include <map>
#include <vector>

using namespace std;

/**
 * @brief findElementAtPosition allows to find which elements are on the map from their position
 * @param elements all the elements of the game
 * @return all the elements on this case
 */
static vector<Element> findElementAtPosition(const vector<GameObject> & elements, const Position & pos) {
    vector<Element> elementsAtPos;
    for(unsigned int elementIndex=0; elementIndex<elements.size(); ++elementIndex) {
        if(elements.at(elementIndex).pos() == pos) {
            elementsAtPos.push_back(elements.at(elementIndex).element());
        }
    }
    return elementsAtPos;
}





/**
 * @brief conversionElementFromText find the litteral corresponding to the enum Element from a string
 */
Element static conversionElementFromText(const string & elem) {
    static map<string, Element> elemConversionFromText = {
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

    return elemConversionFromText.at(elem);
}


//----------------------------------------------------------


/**
 * @brief elemConversionFromElement return a one-char string corresponding to the enum Element we given
 */
string static elemConversionFromElement(const Element & elem) {
    static map<Element, string> elemConversionFromElement = {
        {Element::NULLELEMENT, " "},
        {Element::TEXT_BABA, "B"},
        {Element::TEXT_WALL, "W"},
        {Element::TEXT_ROCK, "R"},
        {Element::TEXT_LAVA, "L"},
        {Element::TEXT_GRASS, "G"},
        {Element::TEXT_METAL, "M"},
        {Element::TEXT_GOOP, "G"},
        {Element::TEXT_FLAG, "F"},
        {Element::IS, "I"},
        {Element::YOU, "Y"},
        {Element::WIN, "W"},
        {Element::STOP, "S"},
        {Element::SINK, "E"},
        {Element::PUSH, "P"},
        {Element::KILL, "K"},
        {Element::BABA, "b"},
        {Element::WALL, "w"},
        {Element::ROCK, "r"},
        {Element::LAVA, "l"},
        {Element::GRASS, "h"},
        {Element::METAL, "m"},
        {Element::GOOP, "g"},
        {Element::FLAG, "f"}
    };

    return elemConversionFromElement.at(elem);
}


//----------------------------------------------------------




/**
 * @brief elemConversionFromElement return a string corresponding to the enum Element we given
 */
string static elemConversionFromElementToFile(const Element & elem) {
    static map<Element, string> elemConversionFromElementToFile = {
        {Element::TEXT_BABA, "text_baba"},
        {Element::TEXT_WALL, "text_wall"},
        {Element::TEXT_ROCK, "text_rock"},
        {Element::TEXT_LAVA, "text_lava"},
        {Element::TEXT_GRASS, "text_grass"},
        {Element::TEXT_METAL, "text_metal"},
        {Element::TEXT_GOOP, "text_goop"},
        {Element::TEXT_FLAG, "text_flag"},
        {Element::IS, "is"},
        {Element::YOU, "you"},
        {Element::WIN, "win"},
        {Element::STOP, "stop"},
        {Element::SINK, "sink"},
        {Element::PUSH, "push"},
        {Element::KILL, "kill"},
        {Element::BABA, "baba"},
        {Element::WALL, "wall"},
        {Element::ROCK, "rock"},
        {Element::LAVA, "lava"},
        {Element::GRASS, "grass"},
        {Element::METAL, "metal"},
        {Element::GOOP, "goop"},
        {Element::FLAG, "flag"}
    };

    return elemConversionFromElementToFile.at(elem);
}


//---------------------------------------------------------------


/**
 * @brief give all elements are a piece to build a rule
 */
vector<Element> static allRules() {
    static vector<Element> allRules = {
        Element::TEXT_BABA,
        Element::TEXT_FLAG,
        Element::TEXT_GOOP,
        Element::TEXT_GRASS,
        Element::TEXT_LAVA,
        Element::TEXT_METAL,
        Element::TEXT_ROCK,
        Element::TEXT_WALL,
        Element::IS,
        Element::PUSH,
        Element::KILL,
        Element::YOU,
        Element::SINK,
        Element::STOP,
        Element::WIN
    };

    return allRules;
}


//-----------------------------------------------------------------

/**
 * @brief return a z-index corresponding to the enum Element we given
 */
unsigned int static getZIndexOfElement(const Element & elem) {
    static map<Element, unsigned int> zIndexOfElement = {
        {Element::TEXT_BABA, 7},
        {Element::TEXT_WALL, 7},
        {Element::TEXT_ROCK, 7},
        {Element::TEXT_LAVA, 7},
        {Element::TEXT_GRASS, 7},
        {Element::TEXT_METAL, 7},
        {Element::TEXT_GOOP, 7},
        {Element::TEXT_FLAG, 7},
        {Element::IS, 7},
        {Element::YOU, 7},
        {Element::WIN, 7},
        {Element::STOP, 7},
        {Element::SINK, 7},
        {Element::PUSH, 7},
        {Element::KILL, 7},
        {Element::BABA, 6},
        {Element::WALL, 2},
        {Element::ROCK, 3},
        {Element::LAVA, 4},
        {Element::GRASS, 1},
        {Element::METAL, 1},
        {Element::GOOP, 4},
        {Element::FLAG, 5}
    };

    return zIndexOfElement.at(elem);
}