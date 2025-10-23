#define CATCH_CONFIG_MAIN  // This tells Catch2 to provide a main() function
#include "../external/Catch2/catch.hpp"
#include "../src/ButtonLogic.hpp"

TEST_CASE("ButtonLogic tests", "[ButtonLogic]") {
    ButtonLogic logic;

    SECTION("getAboutMessage returns correct message") {
        REQUIRE(logic.getAboutMessage() == "This is a simple Qt app built with CMake.\nLearn more at qt.io!");
    }

    SECTION("incrementClickCount increases count correctly") {
        REQUIRE(logic.incrementClickCount() == 1);
        REQUIRE(logic.incrementClickCount() == 2);
    }
}