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


    SECTION("with level 1 and is you = baba (check if rock is been pushable) : ") {
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

    }

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

        GameObject result = mechanics.findAllElement(Element::BABA).at(0);
        Position newPos (8,12);
        GameObject expected = GameObject(Element::BABA, newPos);

        //REQUIRE ( check to win );
        REQUIRE ( mechanics.rules().rules()[Element::YOU].at(0) == Element::TEXT_BABA );
        REQUIRE( result.element() == expected.element() );
        REQUIRE( result.pos() == expected.pos() );

    }


}
