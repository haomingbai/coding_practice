#include <cctype>
#include <stack>
#include <string>
#include <string_view>
#include <utility>

using namespace std;

pair<stack<char>, stack<int>> calc(string_view str) {
  char oper = 0;
  int val = 0;
  stack<char> opers;
  stack<int> vals;

  for (auto it : str) {
    if (isspace(it)) {
      continue;
    }
    switch (it) {
      default:
        val *= 10;
        val += it - '0';
        break;
      case '+':
        oper = '+';
        opers.push(oper);
        vals.push(val);
        val = 0;
        break;
      case '-':
        oper = '-';
        opers.push(oper);
        vals.push(val);
        val = 0;
        break;
    }
  }

  vals.push(val);
  return {(opers), (vals)};
}

int main() {}
