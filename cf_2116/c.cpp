#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>

using std::cin;
using std::gcd;
using std::sort;

template <typename T>
using vec = std::vector<T>;

int calc(vec<int> &arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  int dividor = arr.front();
  for (auto it : arr) {
    dividor = gcd(dividor, it);
  }
  for (auto &it : arr) {
    it /= dividor;
  }

  if (arr.front() == 1) {
    int cnt = 0;
    for (auto i = 0; i < n && arr[i] == 1; i++) {
      cnt++;
    }
    return n - cnt;
  } else {
    vec<vec<int>> dp(n, vec<int>(n));
    
  }
}

int main(void) {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vec<int> v(n);

    for (auto &it : v) {
      cin >> it;
    }
    std::cout << calc(v) << std::endl;
  }
}
