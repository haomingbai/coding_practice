#include <cassert>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

constexpr long long MOD = 998244353;
std::string S, T;

long long Solve(int t, std::string_view sub) {
  // 使用 string key（复制 sub），并用 vector<long long> 做缓存 (-1 表示未计算)
  static std::unordered_map<std::string_view, std::vector<long long>>
      result_map;

  std::string_view key(
      sub);  // 把 string_view 内容安全地复制成 string 作为 map 的 key
  auto it_pair =
      result_map.try_emplace((key), std::vector<long long>(S.size() + 1, -1));
  std::vector<long long> &cache = it_pair.first->second;

  if (cache[t] != -1) {
    return cache[t];
  }

  // base cases
  if (sub.size() == 0) {
    cache[t] = 1;
    return 1;
  }
  if (t == 0) {
    cache[t] = 0;
    return 0;
  }
  if (t == 1) {
    cache[t] = (sub.size() == 1 && S[0] == sub.front()) ? 1 : 0;
    return cache[t];
  }

  long long result = 0;

  // Front-back mode:
  // 划分成左段长度 i（0..sub.size()），右段长度 sub.size()-i
  for (size_t i = 0; i <= sub.size(); ++i) {
    long long a = Solve(t - 1, sub.substr(0, i));
    a %= MOD;
    long long b =
        Solve(t - 1, sub.substr(i));  // 从 i 开始到末尾（i==sub.size() 则为空）
    b %= MOD;
    long long tmp = (a * b) % MOD;
    result += tmp;
    if (result >= MOD) result -= MOD;
  }

  // Front - middle(ai) - back mode:
  // 遍历中间位置 j，如果 sub[j]==S[t-1]，左段来自左 S'_{t-1}，右段来自右
  // S'_{t-1}
  for (size_t j = 0; j < sub.size(); ++j) {
    if (sub[j] == S[t - 1]) {
      long long a = Solve(t - 1, sub.substr(0, j));
      a %= MOD;
      long long b = Solve(t - 1, sub.substr(j + 1));
      b %= MOD;
      long long tmp = (a * b) % MOD;
      result += tmp;
      if (result >= MOD) result -= MOD;
    }
  }

  cache[t] = result % MOD;
  return cache[t];
}

int main() {
  std::cin >> S >> T;
  auto result = Solve(S.size(), std::string_view(T));
  std::cout << result % MOD << std::endl;
  return 0;
}
