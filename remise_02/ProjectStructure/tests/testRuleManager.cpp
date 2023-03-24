#include <catch2/catch_test_macros.hpp>
#include "model/levelloader.h"
#include <map>

TEST_CASE("scanRules() donne l'ensemble des règles à un moment donné de la partie") {
    // Initialiser un level
    /*LevelLoader loader(1);
    LevelMechanics myLevel(loader.createLevel());
    myLevel.rules().scanRules(myLevel.elements());*/

    /*SECTION("LEVEL 1 : ") {
        std::map<Element, std::vector<Element>> expected;

        //remplir expected
        std::vector<Element> aspect;
        //1ère règle
        aspect.push_back(Element::STOP);
        expected.insert(std::make_pair(Element::TEXT_WALL, aspect));
        aspect.clear();
        //2è règle
        aspect.push_back(Element::PUSH);
        expected.insert(std::make_pair(Element::ROCK, aspect));
        aspect.clear();
        //3è règle
        aspect.push_back(Element::YOU);
        expected.insert(std::make_pair(Element::TEXT_BABA, aspect));
        aspect.clear();
        //4è règle
        aspect.push_back(Element::WIN);
        expected.insert(std::make_pair(Element::TEXT_FLAG, aspect));
        aspect.clear();

        //REQUIRE(myLevel.rules().rules() == expected);
    }


    SECTION("Position does not move with invalid direction") {
    }*/
}
