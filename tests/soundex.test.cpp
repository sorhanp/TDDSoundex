//
// Created by sormunen on 10.10.2019.
//

#include <boost/test/unit_test.hpp>
#include <soundex.h>

struct SoundexFixture {
    SoundexFixture() {

    }

    virtual ~SoundexFixture() {

    }
    Soundex soundex;
};

BOOST_FIXTURE_TEST_SUITE(SoundexEncoding, SoundexFixture)

    BOOST_AUTO_TEST_CASE(RetainsSoleLetterOfOneLetterWord) {
        BOOST_REQUIRE_EQUAL(soundex.encode("A"), "A000");
    }

    BOOST_AUTO_TEST_CASE(PadsWithZerosToEnsureThreeDigits) {
        BOOST_REQUIRE_EQUAL(soundex.encode("I"), "I000");
    }

    BOOST_AUTO_TEST_CASE(ReplacesConsonantsWithAppropriateDigits) {
        //The book recommends to use only one assert per test case when test driving
        //This rule is averted here to demonstrate the effectiveness of solution
        BOOST_REQUIRE_EQUAL(soundex.encode("Ab"), "A100");
        BOOST_REQUIRE_EQUAL(soundex.encode("Ac"), "A200");
        BOOST_REQUIRE_EQUAL(soundex.encode("Ad"), "A300");
        BOOST_REQUIRE_EQUAL(soundex.encode("Ax"), "A200");
    }

    BOOST_AUTO_TEST_CASE(IgnoresNonAlphabetics) {
        BOOST_REQUIRE_EQUAL(soundex.encode("A#"), "A000");
    }

BOOST_AUTO_TEST_SUITE_END()