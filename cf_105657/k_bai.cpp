#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ios>

using ll = long long;

int main() {
  {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

  size_t T;
  std::cin >> T;

  while (T--) {
    using namespace std;

    ll n, m, k;
    cin >> n >> m >> k;

    auto get_row = [n, m] (ll i) {
      return (i - 1) / m + 1;
    };

    vector<vector<ll>> indices(n + 1);
    for (size_t i = 1; i <= n; i++) {
      indices[i].reserve(m);
    }

    for (size_t i = 1; i <= n * m; i++) {
      ll p;
      cin >> p;
      indices[get_row(p)].push_back(i);
    }

    if (k >= m) {
      cout << m << '\n';
      continue;
    }

    sort(next(indices.begin()), indices.end(), [k, m](const auto &a, const auto &b) -> bool {
      return a[m - k - 1] < b[m - k - 1];
    });

    cout << max(indices[1][m - k - 1], m) << '\n';
  }
}