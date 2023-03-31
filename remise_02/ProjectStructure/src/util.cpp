#include "model/element.h"
#include "model/gameobject.h"
#include <map>
#include <vector>

using namespace std;

/**
 * @brief findElementAtPosition
 * @param elements
 * @param pos
 * @return
 */
static vector<Element> findElementAtPosition(const vector<GameObject> & elements, const Position & pos) {
    vector<Element> elementsAtPos;
    for(int elementIndex=0; elementIndex<elements.size(); ++elementIndex) {
        if(elements.at(elementIndex).pos() == pos) {
            elementsAtPos.push_back(elements.at(elementIndex).element());
        }
    }
    return elementsAtPos;
}



static map<string, Element> elemConversionFromText_ = {
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

/**
 * @brief conversionElementFromText retrouve le littéral correspondant à l'énum Element à partir d'un string
 * @param elem l'élément à chercher
 * @return l'élément sous forme d'enum
 */
Element static conversionElementFromText(const string & elem) {
    return elemConversionFromText_.at(elem);
}

static map<Element, string> elemConversionFromElement_ = {
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


string static elemConversionFromElement(const Element & elem) {
    return elemConversionFromElement_.at(elem);
}
