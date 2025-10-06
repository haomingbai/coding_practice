#include <iostream>
#include <cstddef>
#include <vector>
#include <string>

struct DSU
{
  std::vector<size_t> parents;

  DSU() : parents(26) {
    for (size_t i = 0; i < 26; i++) {
      parents[i] = i;
    }
  }

  size_t FindRoot(size_t i) {
    if (i == parents[i]) {
      return i;
    }

    parents[i] = FindRoot(parents[i]);
    return parents[i];
  }

  bool InSameSet(size_t a, size_t b) {
    if (FindRoot(a) == FindRoot(b)) {
      return true;
    } else {
      return false;
    }
  }

  void Connect(size_t a, size_t b) {
    a = FindRoot(a);
    b = FindRoot(b);

    parents[a] = parents[b];
  }
};

int main() {
  size_t T;
  std::cin >> T;

  while (T--)
  {
    using namespace std;

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    DSU dsu;

    if (s1.size() != s2.size()) {
      cout << "NO\n";
      continue;
    }

    for (size_t i = 0; i < s1.size(); i++) {
      dsu.Connect(s1[i] - 'a', )
    }
  }
  
}
