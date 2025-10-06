#include <algorithm>
#include <array>
#include <cstddef>
#include <ios>
#include <iostream>
#include <vector>

using ull = unsigned long long;
using ll = long long;

constexpr size_t kMaxN = 1e5 + 1;

struct Person {
  size_t id;
  ll l, r;
};

struct Result {
  std::vector<size_t> seq;
  ll energy;
};

Result StrategyA(const std::array<Person, kMaxN>& data, const size_t n,
                 const ll f) {
  if (n == 1) {
    Result result = {.seq = {1}, .energy = data[0].r - data[0].l};

    if (f < data[0].l) {
      result.energy += (data[0].l - f);
    }

    return result;
  }

  size_t starting = n / 2;

  {
    size_t left = 0, right = n;

    while (left != right) {
      auto mid = (left + right) / 2;
      if (data[mid].l > f) {
        right = mid;
      } else if (data[mid].l < f) {
        left = mid + 1;
      } else {
        left = mid;
        right = mid;
      }
    }

    starting = left;
  }

  Result result = {.energy = 0};

  if (starting == n) {
    starting--;
  }

  result.energy = std::max<ll>(data[starting].l - f, 0);

  result.seq.reserve(n);

  for (size_t i = starting; i < n; i++) {
    result.energy += data[i].r - data[i].l;

    if (i > starting && data[i].l > data[i - 1].r) {
      result.energy += (data[i].l - data[i - 1].r);
    }

    result.seq.emplace_back(data[i].id);
  }

  for (size_t i = 0; i < starting; i++) {
    result.energy += data[i].r - data[i].l;

    if (i && data[i].l > data[i - 1].r) {
      result.energy += (data[i].l - data[i - 1].r);
    }

    result.seq.emplace_back(data[i].id);
  }

  return result;
}

Result StrategyB(const std::array<Person, kMaxN>& data, const size_t n,
                 const ll f) {
  Result result = {.energy = std::max<ll>(data[n - 1].l - f, 0)};
  result.seq.reserve(n);

  for (ptrdiff_t i = n - 1; i >= 0; i--) {
    result.seq.push_back(data[i].id);
    result.energy += data[i].r - data[i].l;
  }

  return result;
}

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

    size_t n;
    ll f;

    cin >> n >> f;
    std::array<Person, kMaxN> dat{};
    for (size_t i = 0; i < n; i++) {
      ll l, r;
      cin >> l >> r;
      dat[i] = {.id = i + 1, .l = l, .r = r};
    }

    sort(dat.begin(), dat.begin() + n, [](const Person& a, const Person& b) {
      if (a.l < b.l) {
        return true;
      } else if (a.l == b.l && a.r < b.r) {
        return a.r < b.r;
      }

      return false;
    });

    auto result_a = StrategyA(dat, n, f);
    auto result_b = StrategyB(dat, n, f);
    
    if (result_a.energy < result_b.energy) {
      cout << result_a.energy << '\n';
      for (auto& it : result_a.seq) {
        cout << it << ' ';
      }
    } else {
      cout << result_b.energy << '\n';
      for (auto& it : result_b.seq) {
        cout << it << ' ';
      }
    }

    cout << '\n';
  }
}