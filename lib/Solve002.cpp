//
// Copyright (c) 2018 Bogdan-Constantin Popescu
// Use, modification and distribution are subject to the MIT license.
// See accompanying file LICENSE or copy at:
// https://github.com/MathPlayer/project-euler/blob/master/LICENSE
//

#include "Solve.hpp"

namespace ProjectEuler {

int Solve002(int n) {
  int a = 1;
  int b = 2;
  int c;
  int result = 0;
  do {
    if (b % 2 == 0) {
      result += b;
    }

    c = a + b;
    a = b;
    b = c;
  } while (b < n);

  return result;
}

};  // namespace ProjectEuler
