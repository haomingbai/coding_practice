#include <cstdint>
#include <iostream>
#include <ostream>
#include <stack>

// uint64_t func(uint64_t n) {
//   if (n == 0) {
//     return 1;
//   } else {
//     return func(n - 1) * n;
//   }
// }

uint64_t func(uint64_t n);

int main() { std::cout << func(20) << std::endl; }

uint64_t func(uint64_t n) {
  std::stack<uint64_t> st;
  uint64_t res = 1;

  while (true) {
    if (n == 0) {
      st.push(1);
      break;
    } else {
      st.push(n);
      res *= n;
      n = n - 1;
    }
  }
  return res;
}
