#include <catch2/catch_test_macros.hpp>
#include "model/levelmechanics.h"
#include "model/levelloader.h"
#include "model/position.h"
#include <map>

TEST_CASE("move()") {

    SECTION("with level 1 and is you = baba in each direction (no constraint on the path) : ") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        //move direction : up
        mechanics.move(Direction::UP);

        GameObject result = mechanics.findAllElement(Element::BABA).at(0);

        Position pos (7,5);
        GameObject expected = GameObject(Element::BABA, pos);

        REQUIRE ( mechanics.rules().rules()[Element::YOU].at(0) == Element::TEXT_BABA );
        REQUIRE( result.element() == expected.element() );
        REQUIRE( result.pos() == expected.pos() );

        //move direction : left
        mechanics.move(Direction::LEFT);

        result = mechanics.findAllElement(Element::BABA).at(0);
        Position newPos (7,4);
        expected = GameObject(Element::BABA, newPos);

        REQUIRE ( mechanics.rules().rules()[Element::YOU].at(0) == Element::TEXT_BABA );
        REQUIRE( result.element() == expected.element() );
        REQUIRE( result.pos() == expected.pos() );

        //move direction : left
        mechanics.move(Direction::LEFT);

        result = mechanics.findAllElement(Element::BABA).at(0);
        Position newPos2 (7,3);
        expected = GameObject(Element::BABA, newPos2);

        REQUIRE ( mechanics.rules().rules()[Element::YOU].at(0) == Element::TEXT_BABA );
        REQUIRE( result.element() == expected.element() );
        REQUIRE( result.pos() == expected.pos() );

        //move direction : down
        mechanics.move(Direction::DOWN);

        result = mechanics.findAllElement(Element::BABA).at(0);
        Position newPos3 (8,3);
        expected = GameObject(Element::BABA, newPos3);

        REQUIRE ( mechanics.rules().rules()[Element::YOU].at(0) == Element::TEXT_BABA );
        REQUIRE( result.element() == expected.element() );
        REQUIRE( result.pos() == expected.pos() );
    }

    SECTION("with level 1 and is you = baba (constraint on the path -> blocked by a wall (is stop)) : ") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        mechanics.move(Direction::UP);
        //move direction : up (HAVE TO BLOCK and stay on position)
        mechanics.move(Direction::UP);

        GameObject result = mechanics.findAllElement(Element::BABA).at(0);
        Position newPos (7,5);
        GameObject expected = GameObject(Element::BABA, newPos);

        REQUIRE ( mechanics.rules().rules()[Element::YOU].at(0) == Element::TEXT_BABA );
        REQUIRE( result.element() == expected.element() );
        REQUIRE( result.pos() == expected.pos() );
    }


    /*SECTION("with level 1 and is you = baba (check if rock is been pushable) : ") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        //path to rock
        mechanics.move(Direction::RIGHT);
        mechanics.move(Direction::RIGHT);
        mechanics.move(Direction::RIGHT);

        GameObject result = mechanics.findAllElement(Element::BABA).at(0);
        Position newPos (8,12);
        GameObject expected = GameObject(Element::BABA, newPos);

        //REQUIRE ( check if a rock moved );
        REQUIRE ( mechanics.rules().rules()[Element::YOU].at(0) == Element::TEXT_BABA );
        REQUIRE( result.element() == expected.element() );
        REQUIRE( result.pos() == expected.pos() );

    }*/

    SECTION("with level 1 and is you = baba (constraint on the path -> win on the flag) : ") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        //path to flag
        mechanics.move(Direction::UP);
        mechanics.move(Direction::RIGHT);
        mechanics.move(Direction::RIGHT);
        mechanics.move(Direction::RIGHT);
        mechanics.move(Direction::RIGHT);
        mechanics.move(Direction::DOWN);
        mechanics.move(Direction::RIGHT);
        mechanics.move(Direction::RIGHT);
        mechanics.move(Direction::RIGHT);

        //REQUIRE ( check to win );
        bool result = mechanics.isWon();
        REQUIRE(result);
    }


}

TEST_CASE("Constraints") {

    SECTION("isMovable() : new pos outside the map (at the high)") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        Position pos(0,0);
        GameObject element(Element::BABA, pos);
        bool result = mechanics.isMovable(Direction::UP, element);

        REQUIRE (!result);
    }

    SECTION("isMovable() : new pos outside the map (at the bottom)") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        Position pos(18,18);
        GameObject element(Element::BABA, pos);
        bool result = mechanics.isMovable(Direction::RIGHT, element);

        REQUIRE (!result);
    }

    SECTION("isMovable() : new pos inside the map (at the high)") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        Position pos(0,0);
        GameObject element(Element::BABA, pos);
        bool result = mechanics.isMovable(Direction::DOWN, element);

        REQUIRE (result);
    }

    SECTION("isMovable() : new pos inside the map (at the bottom)") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        Position pos(18,18);
        GameObject element(Element::BABA, pos);
        bool result = mechanics.isMovable(Direction::LEFT, element);

        REQUIRE (result);
    }

    SECTION("isMovable() : wall is stop on the new pos") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        Position pos(7,3);
        GameObject element(Element::BABA, pos);
        bool result = mechanics.isMovable(Direction::UP, element);
        REQUIRE (!result);
    }

    SECTION("isMovable() : no constraint, everything is good") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        Position pos(7,3);
        GameObject element(Element::BABA, pos);
        bool result = mechanics.isMovable(Direction::DOWN, element);
        REQUIRE (result);
    }

    SECTION("isWon() : flag on the same case that the player (flag is win)") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        Position pos(8,12);
        GameObject element(Element::BABA, pos);
        mechanics.setElementPosition(element);

        bool result = mechanics.isWon();
        REQUIRE (result);
    }

    SECTION("isWon() : flag above the player (not a win)") {
        // initialize the level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        Position pos(9,12);
        GameObject element(Element::BABA, pos);
        mechanics.setElementPosition(element);

        bool result = mechanics.isWon();
        REQUIRE (!result);
    }

    SECTION("isKill() : goop on the same case that the player (goop is sink)") {
        // initialize the level
        LevelLoader loader(4);
        LevelMechanics mechanics(loader.createLevel());

        Position pos(8,7);
        GameObject element(Element::BABA, pos);
        mechanics.setElementPosition(element);

        bool result = mechanics.isKill();
        REQUIRE (result);
    }

    SECTION("isKill() : goop above the player (not a kill)") {
        // initialize the level
        LevelLoader loader(4);
        LevelMechanics mechanics(loader.createLevel());

        Position pos(7,7);
        GameObject element(Element::BABA, pos);
        mechanics.setElementPosition(element);

        bool result = mechanics.isKill();
        REQUIRE (!result);
    }
}
