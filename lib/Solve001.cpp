//
// Copyright (c) 2018 Bogdan-Constantin Popescu
// Use, modification and distribution are subject to the MIT license.
// See accompanying file LICENSE or copy at:
// https://github.com/MathPlayer/project-euler/blob/master/LICENSE
//

#include "Solve.hpp"

namespace ProjectEuler {

int Solve001(int n) {
  int result = 0;

  for (int i = 0; i < n; i++) {
    if (i % 3 && i % 5)
      continue;
    result += i;
  }

  return result;
}

};  // namespace ProjectEuler
