#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "main.h"

TEST_CASE("Copy constructor", "[Copy][constructor]") {
    Stud s("Astrida", "Jablonskyte", 10, {10, 10, 10});
    Stud s1(s);
    REQUIRE(s==s1);}

