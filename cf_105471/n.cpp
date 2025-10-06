/**
 * @file n.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-10-06
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <array>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

using ll = long long;

ll GetArrayLength(ll start, ll stop, ll step) {
  if (step > 0) {
    if (stop <= start) {
      return 0;
    }
    auto n = 1 + (stop - start - 1) / step;
    return n;
  } else {
    if (stop >= start) {
      return 0;
    }
    auto n = 1 + (start - stop - 1) / (-step);
    return n;
  }
}

ll CalculateInnerLoop(ll start, ll stop, ll step) {
  auto n = GetArrayLength(start, stop, step);
  auto result = start * n + ((n - 1) * (n) / 2) * step;
  return result;
}

ll Solve(std::array<std::string, 5>& code) {
  auto init_ans_str = code[0].substr(4);
  ll init_ans = atoll(init_ans_str.c_str());
  ll ans = init_ans;

  char outer_loop_variable = 0;
  {
    std::string for_string = "for";
    auto it =
        search(code[1].begin(), code[1].end(),
               boyer_moore_searcher(for_string.begin(), for_string.end()));
    outer_loop_variable = *(it + 4);
  }

  struct LoopRange {
    ll start = 0;
    ll stop;
    ll step = 1;

    LoopRange() noexcept = default;

    LoopRange(LoopRange&&) noexcept = default;
    LoopRange(const LoopRange&) = default;

    LoopRange& operator=(LoopRange&&) noexcept = default;
    LoopRange& operator=(const LoopRange&) = default;

    LoopRange(ll stop) : start(0), stop(stop), step(1) {}
    LoopRange(ll start, ll stop) : start(start), stop(stop), step(1) {}
    LoopRange(ll start, ll stop, ll step)
        : start(start), stop(stop), step(step) {}
  };

  LoopRange outer_range;
  {
    // Resolve the outer loop range.
    auto left_bracket = find(code[1].begin(), code[1].end(), '(');
    auto right_bracket = find(code[1].begin(), code[1].end(), ')');
    auto loop_str = std::string(left_bracket + 1, right_bracket);

    auto var_num = count(loop_str.begin(), loop_str.end(), ',') + 1;
    switch (var_num) {
      case 1: {
        if (loop_str == "ans") {
          outer_range = LoopRange(ans);
        } else {
          outer_range = LoopRange(atoll(loop_str.c_str()));
        }
        break;
      }

      case 2: {
        auto split_pos = find(loop_str.begin(), loop_str.end(), ',');
        auto start_str = string(loop_str.begin(), split_pos);
        ll start;
        if (start_str == "ans") {
          start = ans;
        } else {
          start = atoll(start_str.c_str());
        }

        auto stop_str = string(split_pos + 1, loop_str.end());
        ll stop;
        if (stop_str == "ans") {
          stop = ans;
        } else {
          stop = atoll(stop_str.c_str());
        }

        outer_range = LoopRange(start, stop);

        break;
      }

      case 3: {
        string split_str = ",";
        auto first_split_pos =
            find_first_of(loop_str.begin(), loop_str.end(), split_str.begin(),
                          split_str.end());
        auto second_split_pos = find_end(loop_str.begin(), loop_str.end(),
                                         split_str.begin(), split_str.end());
        auto start_str = string(loop_str.begin(), first_split_pos);
        ll start;
        if (start_str == "ans") {
          start = ans;
        } else {
          start = atoll(start_str.c_str());
        }

        auto stop_str = string(first_split_pos + 1, second_split_pos);
        ll stop;
        if (stop_str == "ans") {
          stop = ans;
        } else {
          stop = atoll(stop_str.c_str());
        }

        auto step_str = string(second_split_pos + 1, loop_str.end());
        ll step;
        if (step_str == "ans") {
          step = ans;
        } else {
          step = atoll(step_str.c_str());
        }

        outer_range = LoopRange(start, stop, step);

        break;
      }
    }
  }

  if (outer_range.step > 0) {
    for (auto i = outer_range.start; i < outer_range.stop;
         i += outer_range.step) {
      LoopRange inner_range;
      {
        // Resolve the outer loop range.
        auto left_bracket = find(code[2].begin(), code[2].end(), '(');
        auto right_bracket = find(code[2].begin(), code[2].end(), ')');
        auto loop_str = std::string(left_bracket + 1, right_bracket);

        auto var_num = count(loop_str.begin(), loop_str.end(), ',') + 1;
        switch (var_num) {
          case 1: {
            if (loop_str == "ans") {
              inner_range = LoopRange(ans);
            } else if (loop_str[0] == outer_loop_variable) {
              inner_range = LoopRange(i);
            } else {
              inner_range = LoopRange(atoll(loop_str.c_str()));
            }
            break;
          }

          case 2: {
            auto split_pos = find(loop_str.begin(), loop_str.end(), ',');
            auto start_str = string(loop_str.begin(), split_pos);
            ll start;
            if (start_str == "ans") {
              start = ans;
            } else if (start_str[0] == outer_loop_variable) {
              start = i;
            } else {
              start = atoll(start_str.c_str());
            }

            auto stop_str = string(split_pos + 1, loop_str.end());
            ll stop;
            if (stop_str == "ans") {
              stop = ans;
            } else if (stop_str[0] == outer_loop_variable) {
              stop = i;
            } else {
              stop = atoll(stop_str.c_str());
            }

            inner_range = LoopRange(start, stop);

            break;
          }

          case 3: {
            string split_str = ",";
            auto first_split_pos =
                find_first_of(loop_str.begin(), loop_str.end(),
                              split_str.begin(), split_str.end());
            auto second_split_pos =
                find_end(loop_str.begin(), loop_str.end(), split_str.begin(),
                         split_str.end());
            auto start_str = string(loop_str.begin(), first_split_pos);
            ll start;
            if (start_str == "ans") {
              start = ans;
            } else if (start_str[0] == outer_loop_variable) {
              start = i;
            } else {
              start = atoll(start_str.c_str());
            }

            auto stop_str = string(first_split_pos + 1, second_split_pos);
            ll stop;
            if (stop_str == "ans") {
              stop = ans;
            } else if (stop_str[0] == outer_loop_variable) {
              stop = i;
            } else {
              stop = atoll(stop_str.c_str());
            }

            auto step_str = string(second_split_pos + 1, loop_str.end());
            ll step;
            if (step_str == "ans") {
              step = ans;
            } else if (step_str[0] == outer_loop_variable) {
              step = i;
            } else {
              step = atoll(step_str.c_str());
            }

            inner_range = LoopRange(start, stop, step);

            break;
          }
        }
      }

      auto [start, stop, step] = inner_range;
      ans += CalculateInnerLoop(start, stop, step);
    }
  } else {
    for (auto i = outer_range.start; i > outer_range.stop;
         i += outer_range.step) {
      LoopRange inner_range;
      {
        // Resolve the outer loop range.
        auto left_bracket = find(code[2].begin(), code[2].end(), '(');
        auto right_bracket = find(code[2].begin(), code[2].end(), ')');
        auto loop_str = std::string(left_bracket + 1, right_bracket);

        auto var_num = count(loop_str.begin(), loop_str.end(), ',') + 1;
        switch (var_num) {
          case 1: {
            if (loop_str == "ans") {
              inner_range = LoopRange(ans);
            } else if (loop_str[0] == outer_loop_variable) {
              inner_range = LoopRange(i);
            } else {
              inner_range = LoopRange(atoll(loop_str.c_str()));
            }
            break;
          }

          case 2: {
            auto split_pos = find(loop_str.begin(), loop_str.end(), ',');
            auto start_str = string(loop_str.begin(), split_pos);
            ll start;
            if (start_str == "ans") {
              start = ans;
            } else if (start_str[0] == outer_loop_variable) {
              start = i;
            } else {
              start = atoll(start_str.c_str());
            }

            auto stop_str = string(split_pos + 1, loop_str.end());
            ll stop;
            if (stop_str == "ans") {
              stop = ans;
            } else if (stop_str[0] == outer_loop_variable) {
              stop = i;
            } else {
              stop = atoll(stop_str.c_str());
            }

            inner_range = LoopRange(start, stop);

            break;
          }

          case 3: {
            string split_str = ",";
            auto first_split_pos =
                find_first_of(loop_str.begin(), loop_str.end(),
                              split_str.begin(), split_str.end());
            auto second_split_pos =
                find_end(loop_str.begin(), loop_str.end(), split_str.begin(),
                         split_str.end());
            auto start_str = string(loop_str.begin(), first_split_pos);
            ll start;
            if (start_str == "ans") {
              start = ans;
            } else if (start_str[0] == outer_loop_variable) {
              start = i;
            } else {
              start = atoll(start_str.c_str());
            }

            auto stop_str = string(first_split_pos + 1, second_split_pos);
            ll stop;
            if (stop_str == "ans") {
              stop = ans;
            } else if (stop_str[0] == outer_loop_variable) {
              stop = i;
            } else {
              stop = atoll(stop_str.c_str());
            }

            auto step_str = string(second_split_pos + 1, loop_str.end());
            ll step;
            if (step_str == "ans") {
              step = ans;
            } else if (step_str[0] == outer_loop_variable) {
              step = i;
            } else {
              step = atoll(step_str.c_str());
            }

            inner_range = LoopRange(start, stop, step);

            break;
          }
        }
      }

      auto [start, stop, step] = inner_range;
      ans += CalculateInnerLoop(start, stop, step);
    }
  }

  return ans;
}

int main(void) {
  std::array<std::string, 5> code;
  for (auto& it : code) {
    getline(cin, it);
  }
  cout << Solve(code) << endl;
}
