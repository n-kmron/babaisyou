#include <catch2/catch_test_macros.hpp>
#include "model/levelmechanics.h"
#include "model/levelloader.h"
#include "model/position.h"
#include <map>

TEST_CASE("move()") {

    SECTION("with level 1 and is you = baba : ") {
        // Initialiser un level
        LevelLoader loader(1);
        LevelMechanics mechanics(loader.createLevel());

        mechanics.move(Direction::UP);

        GameObject result = mechanics.findAllElement(Element::BABA).at(0);

        Position pos (7,5);
        GameObject expected = GameObject(Element::BABA, pos);

        REQUIRE ( mechanics.rules().rules()[Element::YOU].at(0) == Element::TEXT_BABA );
        REQUIRE( result.element() == expected.element() );
        REQUIRE( result.pos() == expected.pos() );
    }

}
