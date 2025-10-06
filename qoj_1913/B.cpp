#include <bits/stdc++.h>
using namespace std;

#define cn (p[(cn_idx)])
#define cn_nxt (p[((cn_idx) + (1))])

const int N = 3e5 + 10;
const int M = 5e5 + 10;
int n, m, u, v, p[N], cn_idx;
bool vis[N];
set<int> a[M];
vector<pair<int, int>> add_edges;
vector<int> s1, s2;  // s1 call stack, s2, backtrace stack
void dfs(int u) {
  s1.clear(), s2.clear();
  // Add the initial node to call stack
  s1.push_back(u);
  while (!s1.empty()) {

    if (!vis[s1.back()]) {
      cn_idx++;
      if (cn_idx >= n) {
        return;
      }
    }

    vis[s1.back()] = true;

    std::vector<int> to_remove;
    to_remove.reserve(a[s1.back()].size());
    for (auto it : a[s1.back()]) {
      if (vis[it]) {
        to_remove.push_back(it);
      }
    }
    for (auto& it : to_remove) {
      a[s1.back()].erase(it);
    }

    if (a[s1.back()].empty()) {
      while (!s2.empty()) {
        auto call_st_idx = s2.back();

        if (s2.back() != s1.size() - 1) {
          s1.erase(s1.begin() + call_st_idx + 1, s1.end());
          break;
        }

        if (a[s1.back()].empty()) {
          s2.pop_back();
          break;
        } else {
          // !a[s1.back()].empty()
          if (!a[s1.back()].count(cn_nxt)) {
            add_edges.push_back({s1.back(), cn_nxt});
          } else {
            a[s1.back()].erase(cn_nxt);
          }
          s1.push_back(cn_nxt);
          break;
        }
      }
      if (s2.empty()) {
        return;
      }
    } else {
      if (!a[s1.back()].count(cn_nxt)) {
        add_edges.push_back({s1.back(), cn_nxt});
      } else {
        a[s1.back()].erase(cn_nxt);
      }
      if (!a[s1.back()].empty()) {
        s2.push_back(s1.size() - 1);
      }

      s1.push_back(cn_nxt);
    }
  }
}

int main(void) {
  cin >> n >> m;
  s1.reserve(n), s2.reserve(n);
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    a[u].insert(v);
    a[v].insert(u);
  }
  for (int i = 1; i <= n; i++) cin >> p[i];

  cn_idx = 0;

  while (cn_idx < n) {
    dfs(cn_nxt);
  }

  cout << add_edges.size() << '\n';
  for (auto& it : add_edges) {
    cout << it.first << ' ' << it.second << '\n';
  }
}