/**
 *
 * AUTHORS: <David Segal>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114412)) == nospaces("_===_\n(.,.)\n( : )\n(" ")"));
    CHECK(nospaces(snowman(11114413)) == nospaces("_===_\n(.,.)\n( : )\n(___)"));
    CHECK(nospaces(snowman(11114414)) == nospaces("_===_\n(.,.)\n( : )\n(   )"));

    CHECK(nospaces(snowman(11114441)) == nospaces("_===_\n(.,.)\n(   )\n( : )"));
    CHECK(nospaces(snowman(11114432)) == nospaces("_===_\n(.,.)\n(> <)\n(" ")"));
    CHECK(nospaces(snowman(11114423)) == nospaces("_===_\n(.,.)\n(] [)\n(___)"));
    CHECK(nospaces(snowman(11114414)) == nospaces("_===_\n(.,.)\n( : )\n(   )"));

}

TEST_CASE("Bad snowman code: input length") {
    CHECK_THROWS(snowman(420));
    CHECK_THROWS(snowman(23));
    CHECK_THROWS(snowman(1334));
    CHECK_THROWS(snowman(23420));
    CHECK_THROWS(snowman(123123));
    CHECK_THROWS(snowman(1231234));
    CHECK_THROWS(snowman(0)); 
}

TEST_CASE("Bad snowman code: exceeding numbers") {
    CHECK_THROWS(snowman(52341234));
    CHECK_THROWS(snowman(16341234));
    CHECK_THROWS(snowman(12741234));
    CHECK_THROWS(snowman(12381234));
    CHECK_THROWS(snowman(12349234));
    CHECK_THROWS(snowman(12341534));
    CHECK_THROWS(snowman(12341264));
    CHECK_THROWS(snowman(12341230)); 
}

TEST_CASE("Bad snowman code: negative numbers") {
    CHECK_THROWS(snowman(-11114411));
    CHECK_THROWS(snowman(-12341234));
    CHECK_THROWS(snowman(-11233441));
    CHECK_THROWS(snowman(-43214324));
}