//
// Copyright (c) 2018 Bogdan-Constantin Popescu
// Use, modification and distribution are subject to the MIT license.
// See accompanying file LICENSE or copy at:
// https://github.com/MathPlayer/project-euler/blob/master/LICENSE
//

#include <cmath>
#include <vector>

#include "Solve.hpp"

namespace ProjectEuler {

uint64_t Solve003(uint64_t n) {
  std::vector<uint64_t> primes;
  std::vector<uint64_t> factors;

  uint64_t limit = n;
  for (auto i = 2; i <= limit; i++) {
    bool isPrime = true;
    for (auto prime : primes) {
      if (i % prime == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      primes.push_back(i);
      if (limit % i == 0) {
        factors.push_back(i);
        while (limit % i == 0) {
          limit /= i;
        }
      }
    }
  }

  return factors.back();
}

};  // namespace ProjectEuler
