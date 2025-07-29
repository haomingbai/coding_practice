/**
 * @file b.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-24
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int MAX_Q = 1000010;

int n, m, k;
string s[N];

struct Node {
  int x, y, y_prev;
};

// 用于反向BFS的队列
pair<int, int> q2_arr[MAX_Q];
int head2, tail2;

// 用于正向BFS的队列
Node q_arr[MAX_Q];
int head, tail;

// 用于canReachInGY函数的BFS队列
pair<int, int> q_gy_arr[MAX_Q];
int head_gy, tail_gy;

// 标记数组
vector<vector<int>> R;            // 反向BFS的访问标记
vector<vector<int>> global_vis2;  // canReachInGY的时间戳数组
int global_time;                  // 全局时间戳

// 方向数组
int dx[3] = {1, -1, 0};
int dy[3] = {0, 0, 1};
int qx[3] = {1, -1, 0};
int qy[3] = {0, 0, -1};

bool check(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '0';
}

bool canReachInGY(int x, int y, int y_prev) {
  if (y >= m) return false;
  global_time++;
  head_gy = 0;
  tail_gy = 0;

  q_gy_arr[tail_gy++] = {x, y};
  global_vis2[x][y] = global_time;

  int rightCol = min(m - 1, y_prev + k);

  while (head_gy < tail_gy) {
    auto [px, py] = q_gy_arr[head_gy++];
    if (px == 0 && py == m - 1) return true;
    for (int i = 0; i < 3; i++) {
      int nx = px + dx[i], ny = py + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
          global_vis2[nx][ny] == global_time)
        continue;
      if (ny >= y_prev && ny <= rightCol && s[nx][ny] == '1') continue;
      global_vis2[nx][ny] = global_time;
      if (tail_gy < MAX_Q) {
        q_gy_arr[tail_gy++] = {nx, ny};
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
      s[i].reserve(m);
      cin >> s[i];
    }

    // 初始化反向BFS的标记数组
    R.assign(n, vector<int>(m, 0));
    // 初始化canReachInGY的时间戳数组
    global_vis2.assign(n, vector<int>(m, 0));
    global_time = 0;

    // 反向BFS
    head2 = tail2 = 0;
    R[0][m - 1] = 1;
    q2_arr[tail2++] = {0, m - 1};

    while (head2 < tail2) {
      auto [px, py] = q2_arr[head2++];
      for (int i = 0; i < 3; i++) {
        int nx = px + qx[i], ny = py + qy[i];
        if (check(nx, ny) && !R[nx][ny]) {
          R[nx][ny] = 1;
          if (tail2 < MAX_Q) {
            q2_arr[tail2++] = {nx, ny};
          }
        }
      }
    }

    // 正向BFS
    head = tail = 0;
    map<tuple<int, int, int>, int> vis;
    bool flag = false;

    q_arr[tail++] = {0, 0, 0};
    vis[{0, 0, 0}] = 1;

    while (head < tail && !flag) {
      Node node = q_arr[head++];
      int px = node.x, py = node.y, py_prev = node.y_prev;

      if (!R[px][py]) {
        flag = true;
        break;
      }

      for (int i = 0; i < 3; i++) {
        int nx = px + dx[i], ny = py + dy[i];
        if (!check(nx, ny) || vis.count({nx, ny, py})) continue;
        if (canReachInGY(nx, ny, py)) {
          vis[{nx, ny, py}] = 1;
          if (tail < MAX_Q) {
            q_arr[tail++] = {nx, ny, py};
          }
        }
      }
    }

    cout << (flag ? "Yes" : "No") << '\n';
  }
  return 0;
}
