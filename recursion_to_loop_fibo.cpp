#include <unistd.h>

#include <chrono>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <vector>

uint64_t fib_rec(uint64_t n) {
  if (n == 1 || n == 2) {
    return 1;
  }
  if (n == 0) {
    return 0;
  }
  return fib_rec(n - 1) + fib_rec(n - 2);
}

struct status {
  uint64_t n, res;
  unsigned char position = 0;
};

uint64_t fib_nrec(uint64_t n) {
  std::vector<status> st;
  st.reserve(n + 1);
  status init{.n = n};
  st.push_back(init);
  uint64_t lastRes = 0;

process_begin:

  if (st.empty()) {
    return lastRes;
  }

  if (st.back().n == 0) {
    st.pop_back();
    lastRes = 0;
    goto process_begin;
  } else if (st.back().n == 1 || st.back().n == 2) {
    st.pop_back();
    lastRes = 1;
    goto process_begin;
  }

  if (st.back().position == 0) {
    st.back().position++;
    status next = {.n = st.back().n - 1, .res = 0, .position = 0};
    st.push_back(next);
    goto process_begin;
  }

  if (st.back().position == 1) {
    st.back().res += lastRes;
    st.back().position++;
    status next = {.n = st.back().n - 2, .res = 0, .position = 0};
    st.push_back(next);
    goto process_begin;
  }

  if (st.back().position == 2) {
    lastRes += st.back().res;
    st.pop_back();
    goto process_begin;
  }
}

int main() {
  {  // 获取开始时间点
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "开始计时..." << std::endl;

    // 调用你的函数
    for (size_t i = 0; i < 50; i++) {
      fib_rec(30);
    }

    // 获取结束时间点
    auto end = std::chrono::high_resolution_clock::now();

    // 计算持续时间
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "代码执行时间: " << duration.count() << " 微秒" << std::endl;
  }

  {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "开始计时..." << std::endl;

    // 调用你的函数
    for (size_t i = 0; i < 50; i++) {
      fib_nrec(30);
    }

    // 获取结束时间点
    auto end = std::chrono::high_resolution_clock::now();

    // 计算持续时间
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "代码执行时间: " << duration.count() << " 微秒" << std::endl;
  }
  return 0;
}
