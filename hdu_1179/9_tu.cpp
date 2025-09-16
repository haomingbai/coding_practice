/**
 * @file 9_tu.cpp
 * @brief 
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-11
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef unsigned long long ull;
typedef __int128 i128;
typedef unsigned __int128 u128;
void print_u128(u128 x)
{
    if (x == 0) {
        putchar('0');
        return;
    }
    char buf[64];
    int idx = 0;
    while (x > 0) {
        int digit = (int)(x % 10);
        buf[idx++] = '0' + digit;
        x /= 10;
    }
    for (int i = idx - 1; i >= 0; --i) putchar(buf[i]);
}
u128 sum_top_k(ull next_high, ull k)
{
    if (k == 0) return (u128)0;
    u128 K = (u128)k;
    u128 NH = (u128)next_high;
    u128 val = K * ( (u128)2 * NH - K + (u128)1 ) / (u128)2;
    return val;
}
u128 solve_one(ull n, ull w)
{
    ull A = n;
    vector<ull> freq;
    while (true) {
        ull f = A / w;
        freq.push_back(f);
        A = A - f;
        if (A < w) break;
    }
    size_t R = freq.size() + 1;
    vector<ull> freq_per_round(R + 1, 0);
    for (size_t i = 0; i < freq.size(); ++i) freq_per_round[i+1] = freq[i];
    freq_per_round[R] = A;
    ull next_high = n;
    u128 total = (u128)0;
    for (long s = (long)R; s >= 1; --s) {
        ull k = freq_per_round[s];
        if (k == 0) continue;
        u128 seg = sum_top_k(next_high, k); 
        seg = seg * (u128)s;
        total += seg;
        next_high -= k;
    }
    return total;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        ull n, w;
        cin >> n >> w;
        u128 ans = solve_one(n, w);
        print_u128(ans);
        putchar('\n');
    }
    return 0;
}
