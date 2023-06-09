#include <catch2/catch_test_macros.hpp>
#include "model/levelloader.h"
#include "model/rulemanager.h"
#include <map>

TEST_CASE("checkRules() donne l'ensemble des règles à un moment donné de la partie") {

    SECTION("LEVEL 1 : ") {
        // Initialiser un level
        LevelLoader loader("level_1");
        RuleManager rm;
        rm.scanRules(loader.createLevel());

        std::map<Element, std::vector<Element>> expected;
        //ASPECT = KEY
        //remplir expected
        std::vector<Element> material;
        //1st rule
        material.push_back(Element::TEXT_WALL);
        expected.insert(std::make_pair(Element::STOP, material));
        material.clear();
        //2nd rule
        material.push_back(Element::TEXT_ROCK);
        expected.insert(std::make_pair(Element::PUSH, material));
        material.clear();
        //3tr rule
        material.push_back(Element::TEXT_BABA);
        expected.insert(std::make_pair(Element::YOU, material));
        material.clear();
        //4th rule
        material.push_back(Element::TEXT_FLAG);
        expected.insert(std::make_pair(Element::WIN, material));
        material.clear();

        std::map<Element, std::vector<Element>> result = rm.rules();
        REQUIRE( result == expected );
    }


    SECTION("Position does not move with invalid direction") {
    }
}
