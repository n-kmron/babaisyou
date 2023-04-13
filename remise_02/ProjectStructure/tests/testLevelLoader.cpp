#include <catch2/catch_test_macros.hpp>
#include "model/levelloader.h"

TEST_CASE("createLevel()") {

    SECTION("Level 2") {
        // Initialiser un level
        LevelLoader loader(2);
        loader.createLevel();
        REQUIRE(1 == 1);
    }

    SECTION("Level 3") {
        // Initialiser un level
        LevelLoader loader(3);
        loader.createLevel();
        REQUIRE(1 == 1);
    }
}
