#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

#define MAXN 50001

void build(vector<int>& arr, vector<int>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build(arr, tree, left_node, start, mid);
        build(arr, tree, right_node, mid + 1, end);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

void update(vector<int>& tree, int node, int start, int end, int idx, int value) {
    if (start == end) {
        tree[node] += value;
    } else {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        if (idx <= mid) {
            update(tree, left_node, start, mid, idx, value);
        } else {
            update(tree, right_node, mid + 1, end, idx, value);
        }
        tree[node] = tree[left_node] + tree[right_node];
    }
}

int query(vector<int>& tree, int node, int start, int end, int L, int R) {
    if (R < start || L > end) {
        return 0;
    }
    if (L <= start && end <= R) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    int sum_left = query(tree, left_node, start, mid, L, R);
    int sum_right = query(tree, right_node, mid + 1, end, L, R);
    return sum_left + sum_right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> arr(N);
        vector<int> tree(4 * N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        build(arr, tree, 0, 0, N - 1);

        cout << "Case " << t << ":\n";
        while (true) {
            string command;
            cin >> command;
            if (command == "End") break;

            int i, j;
            cin >> i >> j;
            if (command == "Query") {
                cout << query(tree, 0, 0, N - 1, i - 1, j - 1) << '\n';
            } else if (command == "Add") {
                update(tree, 0, 0, N - 1, i - 1, j);
            } else if (command == "Sub") {
                update(tree, 0, 0, N - 1, i - 1, -j);
            }
        }
    }

    return 0;
}

