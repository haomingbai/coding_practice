#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

constexpr long long MOD = 998244353;

long long factorial(long long n) {
  static std::array<long long, 2000> result{1, 0};
  if (result[n]) {
    return result[n];
  } else {
    result[n] = factorial(n - 1) * n;
    result[n] %= MOD;
    return result[n];
  }
}

int main() {
  size_t n;
  std::cin >> n;

  std::vector<long long> a(n);
  // Process IO
  for (auto& it : a) {
    std::cin >> it;
  }

  // Sort the list
  std::sort(a.begin(), a.end());

  // Bucket to stat how many times a elem
  // can occur and how many unique results are there.
  std::vector<size_t> bucket(a.back() + 1, 0);
  bool is_same = true;
  bucket[a[0]]++;
  for (size_t i = 1; i < n; i++) {
    if (bucket[a[i]] == 0) {
      is_same = false;
    }
    bucket[a[i]]++;
  }

  // Calc the num of the schemes.
  long long perm_num = 1;
  long long final_result = 0;
  for (size_t i = 0; i < bucket.size(); i++) {
    auto it = bucket[i];
    if (it) {
      perm_num *= factorial(it);
      perm_num %= MOD;
    }
  }

  // Calc the max - min of each interval.
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < i; j++) {
      final_result += (a[i] - a[j]);
    }
  }

  // If there are two or more unique elems,
  // then multiply the result by 2.
  if (!is_same) {
    perm_num *= 2;
    perm_num %= MOD;
  }

  std::cout << final_result << ' ' << perm_num << std::endl;
}