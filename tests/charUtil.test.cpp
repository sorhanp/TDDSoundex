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

BOOST_FIXTURE_TEST_SUITE(charUtilTesting, charUtilFixture)

    BOOST_AUTO_TEST_CASE(ReturnsSameCharacterInLowercase) {
        BOOST_REQUIRE_EQUAL(charUtil::lower('L'), 'l');
    }

    BOOST_AUTO_TEST_CASE(LowerWorksWithNonAlphabetCharacters) {
        BOOST_REQUIRE_EQUAL(charUtil::lower('1'), '1');
    }

    BOOST_AUTO_TEST_CASE(ReturnsTrueWithLowercaseVowel) {
        BOOST_REQUIRE_EQUAL(charUtil::isVowel('a'), true);
    }

    BOOST_AUTO_TEST_CASE(ReturnsTrueWithUppercaseVowel) {
        BOOST_REQUIRE_EQUAL(charUtil::isVowel('A'), true);
    }

BOOST_AUTO_TEST_SUITE_END()