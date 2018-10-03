//
// Copyright (c) 2018 Bogdan-Constantin Popescu
// Use, modification and distribution are subject to the MIT license.
// See accompanying file LICENSE or copy at:
// https://github.com/MathPlayer/project-euler/blob/master/LICENSE
//

#include "catch.hpp"

#include "Solve.hpp"


TEST_CASE("001 - Example") {
  GIVEN("The value of 10") {
    int n = 10;
    WHEN("The problem 001 is solved") {
      int result = ProjectEuler::Solve001(n);
      THEN("The result is correct") {
        REQUIRE(result == 23);
      }
    }
  }
}

TEST_CASE("001 - Problem") {
  GIVEN("The value of 1000") {
    int n = 1000;
    WHEN("The problem 001 is solved") {
      int result = ProjectEuler::Solve001(n);
      THEN("The result is correct") {
        REQUIRE(result == 233168);
      }
    }
  }
}
