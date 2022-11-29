#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Task A"){
    Profile tests;
    CHECK(tests.getUsername() == "");
    CHECK(tests.getFullName() == "(@)");
    tests.setDisplayName("Will");
    CHECK(tests.getFullName() == "Will(@)");
    tests = Profile("William", "VPI");
    CHECK(tests.getUsername() == "William");
    CHECK(tests.getFullName() == "VPI(@William)");
}

TEST_CASE("Task B & C"){
    Network tests;
    CHECK(tests.addUser("Will", "Hi") == true);
    CHECK(tests.addUser("Will223", "Hi") == false);
    CHECK(tests.addUser("Random", "Hi") == true);
    CHECK(tests.addUser("Will", "Hi") == false);
    CHECK(tests.addUser("Vincent ", "Test") == false);
    CHECK(tests.follow("Z", "Y") == false);
    CHECK(tests.follow("Will", "X") == false);
    CHECK(tests.follow("Random", "Will") == true);
    CHECK(tests.follow("Will", "Will") == true);
}

