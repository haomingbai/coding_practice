#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  s.reserve(1e6);
  cin >> s;

  size_t cNum = 0, pNum = 0;

  for (auto it : s) {
    if (it == 'C') {
      cNum++;
    } else if (it == 'P') {
      pNum++;
    }
  }
  
  if (cNum == 0) {
    cNum++;
  }
  size_t possibleNum = min((cNum - 1) / 2, pNum);
  cout << possibleNum << endl;
}
