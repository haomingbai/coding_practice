#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

typedef int i32;
const i32 mod = 998244353;
std::vector<i32> idx_lst(1e5 + 10);

int calc_r(int p, int q) { return (idx_lst[p] + idx_lst[q]) % mod; }

std::vector<i32> calc(i32 n, const std::vector<i32> &p1, const std::vector<i32> &p2) {
  using vec = std::vector<i32>;
  vec res(n);

  using std::max;
  i32 max_val_p1 = p1[0], max_val_p2 = p2[0];
  size_t max_pos_p1 = 0, max_pos_p2 = 0;
  res[0] = calc_r(max_val_p1, max_val_p2);

  for (size_t i = 1; i < n; i++) {
    // Update the max val and the max pos;
    if (p1[i] > max_val_p1) {
      max_pos_p1 = i;
      max_val_p1 = p1[i];
    }
    if (p2[i] > max_val_p2) {
      max_pos_p2 = i;
      max_val_p2 = p2[i];
    }

    // Decide witch scheme to choose.
    if (max_val_p1 > max_val_p2) {
      res[i] = calc_r(max_val_p1, p2[i - max_pos_p1]);
    } else if (max_val_p1 < max_val_p2) {
      res[i] = calc_r(p1[i - max_pos_p2], max_val_p2);
    } else {
      if (p1[i - max_pos_p2] > p2[i - max_pos_p1]) {
        res[i] = calc_r(p1[i - max_pos_p2], max_val_p2);
      } else {
        res[i] = calc_r(max_val_p1, p2[i - max_pos_p1]);
      }
    }
  }

  return res;
}

void process() {
  using std::cin;
  using std::cout;

  i32 n;
  cin >> n;
  using std::vector;
  vector<i32> p1(n), p2(n);
  for (size_t i = 0; i < n; i++) {
    cin >> p1[i];
  }
  for (size_t i = 0; i < n; i++) {
    cin >> p2[i];
  }

  auto res = calc(n, p1, p2);

  for (auto it : res) {
    cout << it << ' ';
  }
  cout << std::endl;
}

void init() {
  idx_lst[0] = 1;
  for (size_t i = 1; i < idx_lst.size(); i++) {
    idx_lst[i] = (idx_lst[i - 1] * 2) % mod;
  }
}

int main(void) {
  using std::cin;

  int T;
  cin >> T;
  init();

  while (T--) {
    process();
  }
}
