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

BOOST_AUTO_TEST_SUITE_END()