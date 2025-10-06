#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <cstddef>

using namespace std;

constexpr size_t N = 1e6 + 10;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  size_t T;
  cin >> T;

  while (T--)
  {
    std::string str;
    std::vector<uint8_t> v(N);
    size_t n;
    cin >> n;
    cin >> str;

    for (ptrdiff_t i = n - 1, j = N - 1; i >= 0; i--, j--) {
      v[j] = str[i] == '0' ? 0 : 1;
    }

    if (v[N - 1] == v[N - 2] && v[N - 1] == 0) {
      cout << "Yes\n";
    } else if (v[N - 1] == v[N - 2] && v[N - 1] == 1) {
      cout << "No\n";
    } else if (v[N - 1] == 0) {
      if (v[N - 4] == 1 && v[N - 3] == 0) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    } else {
      if (v[N - 4] == v[N - 3] && v[N - 4] == 1) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
  
}