//
// Created by sormunen on 10.10.2019.
//

#include <boost/test/unit_test.hpp>
#include <charUtil.h>

struct charUtilFixture {
    charUtilFixture() {

    }

    virtual ~charUtilFixture() {

    }

};

BOOST_FIXTURE_TEST_SUITE(charUtil_lower, charUtilFixture)

    BOOST_AUTO_TEST_CASE(ReturnsSameCharacterInLowercase) {
        BOOST_REQUIRE_EQUAL(charUtil::lower('L'), 'l');
    }

    BOOST_AUTO_TEST_CASE(ReturnsNonAlphabetCharacters) {
        BOOST_REQUIRE_EQUAL(charUtil::lower('1'), '1');
        BOOST_REQUIRE_EQUAL(charUtil::lower('*'), '*');
        BOOST_REQUIRE_EQUAL(charUtil::lower('\\'), '\\');
    }

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(charUtil_isVowel, charUtilFixture)

    BOOST_AUTO_TEST_CASE(ReturnsTrueWithLowercaseVowel) {
        BOOST_REQUIRE_EQUAL(charUtil::isVowel('a'), true);
    }

    BOOST_AUTO_TEST_CASE(ReturnsTrueWithUppercaseVowel) {
        BOOST_REQUIRE_EQUAL(charUtil::isVowel('A'), true);
    }

    BOOST_AUTO_TEST_CASE(ReturnsTrueWithLowercaseNonVowel) {
        BOOST_REQUIRE_EQUAL(charUtil::isVowel('b'), false);
    }

    BOOST_AUTO_TEST_CASE(ReturnsFalseWithUppercaseNonVowel) {
        BOOST_REQUIRE_EQUAL(charUtil::isVowel('B'), false);
    }

    BOOST_AUTO_TEST_CASE(WorksWithNonAlphabetCharacters) {
        BOOST_REQUIRE_EQUAL(charUtil::isVowel('1'), false);
        BOOST_REQUIRE_EQUAL(charUtil::isVowel('*'), false);
        BOOST_REQUIRE_EQUAL(charUtil::isVowel('\\'), false);
    }

BOOST_AUTO_TEST_SUITE_END()