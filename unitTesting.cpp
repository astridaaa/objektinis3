#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "main.h"

//rule of five testavimas naudojant catch2

TEST_CASE("Copy constructor", "[Copy][constructor]") {
    Stud s("Astrida", "Jablonskyte", 10, {10, 10, 10});
    Stud s1(s);
    REQUIRE(s==s1);}

TEST_CASE("Copy assignment", "[Copy][assignment]"){
    Stud s("Astrida", "Jablonskyte", 10, {10, 10, 10});
    Stud s1=s;
    REQUIRE(s1==s);
}

TEST_CASE("Move constructor", "[Move][constructor]"){
    Stud s("Astrida", "Jablonskyte", 10, {10, 10, 10});
    Stud s1(std::move(s));
    REQUIRE(s1==Stud("Astrida", "Jablonskyte", 10, {10, 10, 10}));
    REQUIRE(s!=s1);
}

TEST_CASE("Move assignment", "[Move][assignment]"){
    Stud s("Astrida", "Jablonskyte", 10, {10, 10, 10}), s1;
    s1 = std::move(s);
    REQUIRE(s1==Stud("Astrida", "Jablonskyte", 10, {10, 10, 10}));
    REQUIRE(s1!=s);
}

TEST_CASE("Destructor", "[Destructor]"){
    Stud *s = new Stud("Astrida", "Jablonskyte", 10, {10, 10, 10});
    s->~Stud();
    REQUIRE(s->getND().empty());
    REQUIRE(s->getVardas()=="");
    REQUIRE(s->getEgzaminas()==0);
    operator delete(s);
}

//default konstruktorius
TEST_CASE("Constructor", "[Constructor]"){
    Stud s, s1;
    CHECK(s == Stud("","",0,{}));
    REQUIRE(s==s1);
}

//getters
TEST_CASE("Getter", "[Getter]"){
    Stud s("Astrida", "Jablonskyte", 10, {10, 10, 10});
    REQUIRE(s.getEgzaminas() == 10);
    REQUIRE_FALSE(s.getPavarde() == "Jablonskyteeee");
}

