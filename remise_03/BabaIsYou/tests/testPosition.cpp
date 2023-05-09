#include <catch2/catch_test_macros.hpp>
#include "model/position.h"

TEST_CASE("next() donne la nouvelle position à partir d'une direction donnée") {
    // Créer une position initiale
    Position p(5, 5);

    SECTION("Direction haut") {
        Position p_next = p.next(Direction::UP);
        REQUIRE(p_next.col() == 5);
        REQUIRE(p_next.row() == 4);
    }

    SECTION("Direction bas") {
        Position p_next = p.next(Direction::DOWN);
        REQUIRE(p_next.col() == 5);
        REQUIRE(p_next.row() == 6);
    }

    SECTION("Direction gauche") {
        Position p_next = p.next(Direction::LEFT);
        REQUIRE(p_next.col() == 4);
        REQUIRE(p_next.row() == 5);
    }

    SECTION("Direction droite") {
        Position p_next = p.next(Direction::RIGHT);
        REQUIRE(p_next.col() == 6);
        REQUIRE(p_next.row() == 5);
    }


    SECTION("Position does not move with invalid direction") {
        Position p_next = p.next(static_cast<Direction>(4)); // invalid direction
        REQUIRE(p_next.col() == 5);
        REQUIRE(p_next.row() == 5);
    }
}

TEST_CASE("operator== compare 2 positions") {
    Position p(5, 5);

    SECTION("same positions") {
        Position p2(5,5);
        REQUIRE(p == p2);
    }

    SECTION("same positions") {
        Position p2(4,6);
        REQUIRE(p != p2);
    }



    SECTION("Position does not move with invalid direction") {
        Position p_next = p.next(static_cast<Direction>(4)); // invalid direction
        REQUIRE(p_next.col() == 5);
        REQUIRE(p_next.row() == 5);
    }
}
