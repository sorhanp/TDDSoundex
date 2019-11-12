//
// Created by sormunen on 10.10.2019.
//

#include <boost/test/unit_test.hpp>
#include <stringUtil.h>

struct stringUtilFixture {
    stringUtilFixture() {

    }

    virtual ~stringUtilFixture() {

    }

};

BOOST_FIXTURE_TEST_SUITE(stringUtil_upperFront, stringUtilFixture)

    BOOST_AUTO_TEST_CASE(ReturnsStringWithStartingUppercaseLetter) {
        BOOST_REQUIRE_EQUAL(stringUtil::upperFront("test"), "T");
    }

    BOOST_AUTO_TEST_CASE(WorksWithAlreadyUppercaseStrings) {
        BOOST_REQUIRE_EQUAL(stringUtil::upperFront("Test"), "T");
    }

    BOOST_AUTO_TEST_CASE(WorksWithNonAlphabetCharacters) {
        BOOST_REQUIRE_EQUAL(stringUtil::upperFront("*est"), "*");
    }

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(stringUtil_head, stringUtilFixture)

    BOOST_AUTO_TEST_CASE(ReturnsStringWithFirstLetterOfWord) {
        BOOST_REQUIRE_EQUAL(stringUtil::head("Test"), "T");
        BOOST_REQUIRE_EQUAL(stringUtil::head("test"), "t");
    }

    BOOST_AUTO_TEST_CASE(WorksWithNonAlphabetCharacters) {
        BOOST_REQUIRE_EQUAL(stringUtil::head("*est"), "*");
    }

BOOST_AUTO_TEST_SUITE_END()