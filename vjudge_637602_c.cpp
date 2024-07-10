/*************************************************************************
    > File Name: vjudge_637602_c.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月08日 星期一 21时37分58秒
 ************************************************************************/

#include <cstddef>
#include <cstdio>
#include <iostream>
#include<vector>

using namespace std;

long long tree[400000];

long long res[100000];

long long dat[100000];


using namespace std;

const long long MOD = 1000000007;

vector<long long> calculateResults(const vector<long long>& A, const vector<pair<int, int>>& queries) {
    vector<long long> results;
    for (const auto& query : queries) {
        int L = query.first - 1;
        int R = query.second - 1;
        if (L == R) {
            results.push_back(A[L] % MOD);
            continue;
        }
        if (L + 1 == R) {
            results.push_back(A[R] % MOD);
            continue;
        }
        long long F_L = A[L] % MOD;
        long long F_L1 = A[L + 1] % MOD;
        for (int i = L + 2; i <= R; ++i) {
            long long F_L2 = (F_L1 + F_L * A[i] % MOD) % MOD;
            F_L = F_L1;
            F_L1 = F_L2;
        }
        results.push_back(F_L1);
    }
    return results;
}

template <typename T> void make_tree(T *src, size_t len, T *tree, size_t node, size_t left, size_t right)
{
    if (left == right)
    {
        tree[node] = src[node];
    }
    else
    {
        size_t mid = (left + right) / 2;
        make_tree(src, len, tree, 2 * node + 1, left, mid);
        make_tree(src, len, tree, 2 * node + 1, mid + 1, right);
        tree[node] = tree[2 * node + 1] * tree[2 * node + 2] % 1000000007;
    }
}

template <typename T> T quiry_tree(T *tree, size_t node, size_t start, size_t end, size_t left, size_t right)
{
    if (start > right || end < left)
    {
        return 1;
    }
    else if (start <= left && end >= right)
    {
        return tree[node];
    }
    else
    {
        size_t mid = (left + right) / 2;
        T product_left = quiry_tree(tree, 2 * node + 1, start, end, left, mid);
        T product_right = quiry_tree(tree, 2 * node + 2, start, end, mid + 1, right);
        return product_right * product_left % 1000000007;
    }
}

/*
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M;
        cin >> N >> M;
        for (int j = 0; j < N; j++)
        {
            cin >> dat[j];
        }
		make_tree(dat, N, tree, 0, 0, N - 1);
		for (int j = 0, l, r; j < M; j++)
		{
			cin >> l >> r;
			l--, r--;
			long long res;
			res = 0;
			switch(r - l)
			{
				case 0:
					cout << dat[l] << '\n';
					break;
				case 1:
					cout << dat[r] << '\n';
					break;
				default:
					res += dat[l] + dat[l + 1];
					for(int k = l + 2; k <= r; k++)
					{
						res += quiry_tree(tree, 0, l, k - 2, 0, N-1) * dat[k];
						res %= 1000000007;
					}
					cout << res << '\n';
			}
		}
    }
}
*/

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, M;
        cin >> N >> M;
        vector<long long> A(N);
        for (int j = 0; j < N; ++j) {
            cin >> A[j];
        }
        vector<pair<int, int>> queries(M);
        for (int j = 0; j < M; ++j) {
            int l, r;
            cin >> l >> r;
            queries[j] = {l, r};
        }
        vector<long long> results = calculateResults(A, queries);
        for (const long long& result : results) {
            cout << result << '\n';
        }
    }
    return 0;
}

