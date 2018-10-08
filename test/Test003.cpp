//
// Copyright (c) 2018 Bogdan-Constantin Popescu
// Use, modification and distribution are subject to the MIT license.
// See accompanying file LICENSE or copy at:
// https://github.com/MathPlayer/project-euler/blob/master/LICENSE
//

#include "catch.hpp"

#include "Solve.hpp"


TEST_CASE("003 - Example") {
  GIVEN("The value of 13195") {
    uint64_t n = 13195;
    WHEN("The problem 003 is solved") {
      uint64_t result = ProjectEuler::Solve003(n);
      THEN("The result is correct") {
        REQUIRE(result == 29);
      }
    }
  }
}

TEST_CASE("003 - Problem") {
  GIVEN("The value of 600851475143") {
    uint64_t n = 600851475143;
    WHEN("The problem 001 is solved") {
      uint64_t result = ProjectEuler::Solve003(n);
      THEN("The result is correct") {
        REQUIRE(result == 6857);
      }
    }
  }
}
