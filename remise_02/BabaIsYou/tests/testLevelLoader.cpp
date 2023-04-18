#include <catch2/catch_test_macros.hpp>
#include "model/levelloader.h"

TEST_CASE("createLevel()") {

    SECTION("Level 1") {
        // Initialiser un level
        LevelLoader loader("level_1");
        loader.createLevel();
        unsigned int result = loader.numLevel();
        REQUIRE(result == 1);
    }

    SECTION("Level 3") {
        // Initialiser un level
        LevelLoader loader("level_3");
        loader.createLevel();
        unsigned int result = loader.numLevel();
        REQUIRE(result == 3);
    }
}
