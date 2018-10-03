//
// Copyright (c) 2018 Bogdan-Constantin Popescu
// Use, modification and distribution are subject to the MIT license.
// See accompanying file LICENSE or copy at:
// https://github.com/MathPlayer/project-euler/blob/master/LICENSE
//

#include "catch.hpp"

#include "Solve.hpp"


TEST_CASE("002 - Problem") {
  GIVEN("The value of four million") {
    int n = 4000000;
    WHEN("The problem 002 is solved") {
      int result = ProjectEuler::Solve002(n);
      THEN("The result is correct") {
        REQUIRE(result == 4613732);
      }
    }
  }
}
