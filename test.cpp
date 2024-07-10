#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

// 计算前缀乘积数组
vector<long long> computePrefixProduct(const vector<long long>& A) {
    int N = A.size();
    vector<long long> prefixProduct(N);
    prefixProduct[0] = A[0] % MOD;
    for (int i = 1; i < N; ++i) {
        prefixProduct[i] = (prefixProduct[i - 1] * A[i]) % MOD;
    }
    return prefixProduct;
}

// 计算 x 的模逆元
long long modInverse(long long x) {
    long long res = 1, k = MOD - 2;
    while (k) {
        if (k % 2) res = (res * x) % MOD;
        x = (x * x) % MOD;
        k /= 2;
    }
    return res;
}

// 计算区间乘积
long long rangeProduct(const vector<long long>& prefixProduct, int L, int R) {
    if (L == 0) return prefixProduct[R];
    return (prefixProduct[R] * modInverse(prefixProduct[L - 1])) % MOD;
}

vector<long long> calculateResults(const vector<long long>& A, const vector<pair<int, int>>& queries) {
    vector<long long> results;
    vector<long long> prefixProduct = computePrefixProduct(A);

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
            long long product = rangeProduct(prefixProduct, L, i - 2);
            long long F_L2 = (F_L1 + F_L * product % MOD * A[i] % MOD) % MOD;
            F_L = F_L1;
            F_L1 = F_L2;
        }
        results.push_back(F_L1);
    }
    return results;
}

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

