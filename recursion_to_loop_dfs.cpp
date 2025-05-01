#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& nums, vector<bool>& used, vector<int>& path,
         vector<vector<int>>& result) {
  if (path.size() == nums.size()) {  // 递归终止条件
    result.push_back(path);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (used[i]) continue;  // 如果当前数字已经用过，则跳过
    used[i] = true;
    path.push_back(nums[i]);

    dfs(nums, used, path, result);  // 递归

    path.pop_back();  // 回溯
    used[i] = false;
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> path;
  vector<bool> used(nums.size(), false);
  dfs(nums, used, path, result);
  return result;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> result = permute(nums);

  for (const auto& perm : result) {
    for (int num : perm) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
