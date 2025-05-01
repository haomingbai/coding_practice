#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>

using namespace std;

struct dsu {
  vector<size_t> pa;

  explicit dsu(size_t size) : pa(size) { iota(pa.begin(), pa.end(), 0); }

  size_t find(size_t x) { return pa[x] == x ? x : find(pa[x]); }
};

int main() {
  dsu d(10);
  cout << d.find(5) << endl;
}
