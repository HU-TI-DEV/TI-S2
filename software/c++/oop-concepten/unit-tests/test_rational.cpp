#include "catch.hpp"
#include "ostream"
#include "rational.hpp"
#include "sstream"

uint32_t factorial (uint32_t number)
{
    return number <= 1 ? number : factorial (number - 1) * number;
}

TEST_CASE ("Factorials are computed", "[factorial]")
{
    REQUIRE (factorial (1) == 1);
    REQUIRE (factorial (2) == 2);
    REQUIRE (factorial (3) == 6);
    REQUIRE (factorial (10) == 3'628'800);
}

TEST_CASE ("constructor, two_parameters")
{
    rational v (3, 4);
    std::stringstream s;
    s << v;
    REQUIRE (s.str () == "[0x0003/0x0004]");
}

TEST_CASE ("equality, equal")
{
    rational v (1, 2);
    REQUIRE (v == rational (1, 2));
}

TEST_CASE ("equality, unequal")
{
    rational v (1, 2);
    REQUIRE (!(v == rational (1, 3)));
}

TEST_CASE ("constructor, two_parameters; reduction")
{
    rational v (10, 2);
    REQUIRE (v == rational (5, 1));
}

TEST_CASE ("constructor, one parameter")
{
    rational v (6);
    REQUIRE (v == rational (6, 1));
}

TEST_CASE ("multiply by integer")
{
    rational v (3, 4);
    rational x = v * 7;
    REQUIRE (v == rational (3, 4));
    REQUIRE (x == rational (21, 4));
}

TEST_CASE ("multiply by integer; reduction")
{
    rational v (3, 10);
    rational x = v * 5;
    REQUIRE (v == rational (3, 10));
    REQUIRE (x == rational (3, 2));
}

TEST_CASE ("multiply by rational")
{
    rational v (3, 4);
    rational x = v * rational (9, 7);
    REQUIRE (v == rational (3, 4));
    REQUIRE (x == rational (27, 28));
}

TEST_CASE ("multiply by rational; reduction")
{
    rational v (3, 10);
    rational x = v * rational (4, 6);
    REQUIRE (v == rational (3, 10));
    REQUIRE (x == rational (1, 5));
}

TEST_CASE ("add rational into rational")
{
    rational v (3, 10);
    v += rational (6, 7);
    REQUIRE (v == rational (81, 70));
}

TEST_CASE ("add rational into rational; reduction")
{
    rational v (23, 147);
    v += rational (5, 91);
    REQUIRE (v == rational (404, 1911));
}

TEST_CASE ("add rational into rational; return value")
{
    rational v (1, 2);
    rational x = (v += rational (1, 4));
    REQUIRE (v == rational (3, 4));
    REQUIRE (x == rational (3, 4));
}

TEST_CASE ("multiply rational into rational")
{
    rational v (3, 10);
    v *= rational (1, 2);
    REQUIRE (v == rational (3, 20));
}

TEST_CASE ("multiply rational into rational; reduction")
{
    rational v (2, 3);
    v *= rational (3, 2);
    REQUIRE (v == rational (1, 1));
}

TEST_CASE ("multiply rational into rational; return value")
{
    rational v (3, 10);
    rational x = (v *= rational (1, 2));
    REQUIRE (x == rational (3, 20));
}