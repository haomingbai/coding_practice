#include <cstddef>
#include <cstdint>
#include <ios>
#include <iostream>

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

    int64_t l, r;
    cin >> l >> r;

    auto len = r - l + 1;

    enum Winner { ALICE, BOB };

    Winner winner;
    if (len % 2) {
      winner = ALICE;
    } else {
      winner = BOB;
    }

    Winner changer;
    if (l % 2) {
      changer = ALICE;
    } else {
      changer = BOB;
    }

    if (changer == winner) {
      cout << (winner == ALICE ? "Alice\n" : "Bob\n");
    } else {
      bool can_change;
      if (changer == ALICE) {
        if (l * 2 <= r) {
          can_change = true;
        } else {
          can_change = false;
        }
      } else {
        // changer == BOB
        if ((l + 1) * 2 <= r) {
          can_change = true;
        } else {
          can_change = false;
        }
      }
      if (can_change) {
        cout << (changer == ALICE ? "Alice\n" : "Bob\n");
      } else {
        cout << (winner == ALICE ? "Alice\n" : "Bob\n");
      }
    }
  }
}