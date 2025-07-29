#include <algorithm>
#include <cstddef>
#include <iostream>

typedef long long ll;

int main(void) {
  using std::cin;
  using std::cout;

  size_t T;
  cin >> T;
  while (T--) {
    ll g_hp, gk_hp, f_hp, fk_hp;
    cin >> g_hp >> f_hp >> gk_hp >> fk_hp;

    using std::min;
    
    if (min({g_hp, gk_hp, f_hp, fk_hp}) == fk_hp || min({gk_hp, g_hp, fk_hp, f_hp}) == f_hp) {
      cout << "Gellyfish\n";
    } else {
      cout << "Flower\n";
    }
  }
}
