#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  size_t value = 0;
  size_t marked = 0;
  size_t parent = 0;
  size_t numOfChildren = 0;
};

struct Path {
  vector<size_t> path;
  size_t size() { return path.size(); }
  bool operator<(const Path &b) const {
    return this->path.size() > b.path.size();
  }
};

int main() {
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;

    vector<TreeNode> vec(n + 1);
    priority_queue<Path> paths;
    for (size_t i = 0; i <= n; i++) {
      vec[i].value = i;
    }

    for (size_t i = 2; i <= n; i++) {
      size_t p;
      cin >> p;
      vec[i].parent = p;
      vec[p].numOfChildren++;
    }

    auto it = prev(vec.end());

    while (it->value != 0) {
      if (it->numOfChildren == 0) {
        TreeNode *nodeToProcess = &*it;
        Path currentPath;

        nodeToProcess->marked++;
        currentPath.path.push_back(nodeToProcess->value);
        nodeToProcess = &vec[nodeToProcess->parent];

        while (nodeToProcess->value != 0 &&
               nodeToProcess->marked < nodeToProcess->numOfChildren) {
          nodeToProcess->marked++;
          currentPath.path.push_back(nodeToProcess->value);
          nodeToProcess = &vec[nodeToProcess->parent];
        }

        paths.push(currentPath);
      }
      it--;
    }

    size_t length = 0;
    while (!paths.empty()) {
      Path currentPath = paths.top();
      paths.pop();
      TreeNode *node = &vec[currentPath.path.back()];
      length = max(length, currentPath.size() > 0 ? currentPath.size() - 1 : 0);

      if (node->marked >= node->numOfChildren || node->value == 0) {
        continue;
      }

      node = &vec[node->parent];
      currentPath.path.push_back(node->value);
      node->marked++;
      node = &vec[node->parent];

      while (node->value != 0 && node->marked < node->numOfChildren) {
        node->marked++;
        currentPath.path.push_back(node->value);
        node = &vec[node->parent];
      }
      paths.push(currentPath);
    }
    cout << length << endl;
  }
}
