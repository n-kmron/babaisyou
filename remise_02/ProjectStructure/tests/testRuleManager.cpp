#include <catch2/catch_test_macros.hpp>
#include "model/levelloader.h"
#include "model/rulemanager.h"
#include <map>

TEST_CASE("checkRules() donne l'ensemble des règles à un moment donné de la partie") {

    SECTION("LEVEL 1 : ") {
        // Initialiser un level
        LevelLoader loader(1);
        RuleManager rm;
        rm.checkRules(loader.createLevel());

        std::map<Element, std::vector<Element>> expected;
        //ASPECT = KEY
        //remplir expected
        std::vector<Element> material;
        //1ère règle
        material.push_back(Element::TEXT_WALL);
        expected.insert(std::make_pair(Element::STOP, material));
        material.clear();
        //2è règle
        material.push_back(Element::TEXT_ROCK);
        expected.insert(std::make_pair(Element::PUSH, material));
        material.clear();
        //3è règle
        material.push_back(Element::TEXT_BABA);
        expected.insert(std::make_pair(Element::YOU, material));
        material.clear();
        //4è règle
        material.push_back(Element::TEXT_FLAG);
        expected.insert(std::make_pair(Element::WIN, material));
        material.clear();

        std::map<Element, std::vector<Element>> result = rm.rules();
        /*for (const auto& pair : result) {
                std::cout << "Clé : " << static_cast<int>(pair.first) << std::endl;
                std::cout << "Valeurs :";
                for (const auto& value : pair.second) {
                    std::cout << " " << static_cast<int>(value);
                }
                std::cout << std::endl;
            }
        std::cout << "EXP" << std::endl;

        for (const auto& pair : expected) {
                std::cout << "Clé : " << static_cast<int>(pair.first) << std::endl;
                std::cout << "Valeurs :";
                for (const auto& value : pair.second) {
                    std::cout << " " << static_cast<int>(value);
                }
                std::cout << std::endl;
        }*/
        REQUIRE( result == expected );
    }


    SECTION("Position does not move with invalid direction") {
    }
}
