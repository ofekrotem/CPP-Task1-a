/**
 * AUTHORS: Ofek Rotem
 * 
 * Date: 2021-03
 */
#include <iostream>
#include "doctest.h"
#include "mat.hpp"
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


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '&', '!')) == nospaces("&&&&&&&&&\n"
													 "&!!!!!!!&\n"
													 "&!&&&&&!&\n"
													 "&!&!!!&!&\n"
													 "&!&&&&&!&\n"
													 "&!!!!!!!&\n"
													 "&&&&&&&&&"));

	CHECK(nospaces(mat(11, 5, '@', '-')) == nospaces("@@@@@@@@@@@\n"
                                                     "@---------@\n"
                                                     "@-@@@@@@@-@\n"
                                                     "@---------@\n"
                                                     "@@@@@@@@@@@"));

	CHECK(nospaces(mat(11, 5, '@', '-')) == nospaces("@@@@@@@@@@@\n"
                                                     "@---------@\n"
                                                     "@-@@@@@@@-@\n"
                                                     "@---------@\n"
                                                     "@@@@@@@@@@@"));

	CHECK(nospaces(mat(3, 7, 'O', 'R')) == nospaces("OOO\n"
                                                    "ORO\n"
                                                    "ORO\n"
                                                    "ORO\n"
                                                    "ORO\n"
                                                    "ORO\n"
                                                    "OOO"));

}

TEST_CASE("Even rows or column input") {
    CHECK_THROWS(mat(8, 5, '$', '%'));
	CHECK_THROWS(mat(9, 4, '$', '%'));
	CHECK_THROWS(mat(8, 4, '$', '%'));
	CHECK_THROWS(mat(8, 7, 'A', 'a'));
}

TEST_CASE("Negetive or zero rows or column input") {
	CHECK_THROWS(mat(-7, 5, '!', '$'));
	CHECK_THROWS(mat(-7, -5, '!', '$'));
	CHECK_THROWS(mat(7, -5, '!', '$'));
	CHECK_THROWS(mat(7, 0, '!', '$'));
	CHECK_THROWS(mat(0, 7, '!', '$'));
	CHECK_THROWS(mat(0, 0, '!', '$'));
	CHECK_THROWS(mat(0, -4, '$', '%'));
}

TEST_CASE("Very bad input") {
	CHECK_THROWS(mat(-7, 5, '!', '!'));
	CHECK_THROWS(mat(-7, -5, '!', '!'));
	CHECK_THROWS(mat(8, -5, '$', '$'));
	CHECK_THROWS(mat(0, 7, '$', '$'));
}

TEST_CASE("Small input") {
	CHECK(nospaces(mat(1,1,'$','!')) == nospaces("$"));
	CHECK(nospaces(mat(1,1,'A','b')) == nospaces("A"));
}

TEST_CASE("Big input") {
	CHECK(nospaces(mat(45, 37, '$', '^')) ==  nospaces("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
														"$^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$\n"
														"$^$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$^$\n"
														"$^$^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$^$\n"
														"$^$^$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$^$^$\n"
														"$^$^$^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$^$^$\n"
														"$^$^$^$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$^$^$^$\n"
														"$^$^$^$^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$^$^$^$\n"
														"$^$^$^$^$$$$$$$$$$$$$$$$$$$$$$$$$$$$$^$^$^$^$\n"
														"$^$^$^$^$^^^^^^^^^^^^^^^^^^^^^^^^^^^$^$^$^$^$\n"
														"$^$^$^$^$^$$$$$$$$$$$$$$$$$$$$$$$$$^$^$^$^$^$\n"
														"$^$^$^$^$^$^^^^^^^^^^^^^^^^^^^^^^^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$$$$$$$$$$$$$$$$$$$$$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$^^^^^^^^^^^^^^^^^^^$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$^$$$$$$$$$$$$$$$$$^$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$^$^^^^^^^^^^^^^^^$^$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$^$^$$$$$$$$$$$$$^$^$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$^$^$^^^^^^^^^^^$^$^$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$^$^$^$$$$$$$$$^$^$^$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$^$^$^^^^^^^^^^^$^$^$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$^$^$$$$$$$$$$$$$^$^$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$^$^^^^^^^^^^^^^^^$^$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$^$$$$$$$$$$$$$$$$$^$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$^^^^^^^^^^^^^^^^^^^$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^$$$$$$$$$$$$$$$$$$$$$^$^$^$^$^$^$\n"
														"$^$^$^$^$^$^^^^^^^^^^^^^^^^^^^^^^^$^$^$^$^$^$\n"
														"$^$^$^$^$^$$$$$$$$$$$$$$$$$$$$$$$$$^$^$^$^$^$\n"
														"$^$^$^$^$^^^^^^^^^^^^^^^^^^^^^^^^^^^$^$^$^$^$\n"
														"$^$^$^$^$$$$$$$$$$$$$$$$$$$$$$$$$$$$$^$^$^$^$\n"
														"$^$^$^$^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$^$^$^$\n"
														"$^$^$^$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$^$^$^$\n"
														"$^$^$^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$^$^$\n"
														"$^$^$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$^$^$\n"
														"$^$^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$^$\n"
														"$^$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$^$\n"
														"$^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$\n"
														"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"));
}