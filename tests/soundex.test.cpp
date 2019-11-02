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

    //Example of disabled test:
    BOOST_AUTO_TEST_CASE(ReplacesMultipleConsonantsWithDigitsDisabled, *boost::unit_test::disabled()) {
        BOOST_REQUIRE_EQUAL(soundex.encode("Acdl"), "A234");
    }

    BOOST_AUTO_TEST_CASE(ReplacesMultipleConsonantsWithDigits) {
        BOOST_REQUIRE_EQUAL(soundex.encode("Acdl"), "A234");
    }

    BOOST_AUTO_TEST_CASE(LimitsLengthToFourCharacters) {
        BOOST_REQUIRE_EQUAL(soundex.encode("Dcdlb").length(), 4);
    }

    //Letter w, h and y are ignored
    BOOST_AUTO_TEST_CASE(IgnoresVowelLikeLetters) {
        BOOST_REQUIRE_EQUAL(soundex.encode("Baeiouhycdl"), "B234");
    }

    //Uppercase w, h and y are ignored as well
    BOOST_AUTO_TEST_CASE(IgnoresVowelLikeLettersUppercase) {
        BOOST_REQUIRE_EQUAL(soundex.encode("BaAeEiIoOuUhHyYcdl"), "B234");
    }

    //RULE: Two adjacent letters must encode to same digit.
    BOOST_AUTO_TEST_CASE(CombinesDuplicateEncodings) {
        //precondition assertions that demonstrate the rule mentioned abobe
        BOOST_REQUIRE_EQUAL(soundex.encodedDigit('b'), soundex.encodedDigit('f'));
        BOOST_REQUIRE_EQUAL(soundex.encodedDigit('c'), soundex.encodedDigit('g'));
        BOOST_REQUIRE_EQUAL(soundex.encodedDigit('d'), soundex.encodedDigit('t'));

        BOOST_REQUIRE_EQUAL(soundex.encode("Abfcgdt"), "A123");
    }

    BOOST_AUTO_TEST_CASE(UppercasesFirstLetter) {
        BOOST_REQUIRE_EQUAL(soundex.encode("abcd").substr(0,1), "A");
    }

BOOST_AUTO_TEST_SUITE_END()