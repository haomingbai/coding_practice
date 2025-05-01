#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

int main() {
  string originalStr;
  cin >> originalStr;
  string_view viewString(originalStr);
  vector<string_view> processed;

  for (auto it = viewString.begin(); it != viewString.end();) {
    if (*it == '1') {
      auto toProc = it;
      size_t numOf1 = 0;
      while (toProc != viewString.end() && *toProc == '1') {
        numOf1++;
        toProc++;
      }
      processed.emplace_back(
          viewString.substr(it - viewString.begin(), toProc - it));
      it = toProc;
    } else {
      it++;
    }
  }

  double_t val = 0;
  for (auto &&it : processed) {
    switch (it.length()) {
      case 1:
        val += 1;
        break;
      case 2:
        val += sqrt((double_t)2);
        break;
      default:
        auto currentLength = it.length();
        double_t tmp = 0;
        if (currentLength % 2 == 0) {
          currentLength -= 3;
          tmp += sqrt((double_t)2);
        }
        currentLength -= (currentLength / 2);
        tmp += currentLength;
        val += tmp;
    }
  }
  cout << setprecision(11) << val << endl;
}
