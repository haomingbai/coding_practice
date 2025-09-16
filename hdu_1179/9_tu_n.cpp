#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
void print128(i128 x)
{
    if (x == 0) { cout << '0'; return; }
    if (x < 0) { cout << '-'; x = -x; }
    string s;
    while (x) {
        int digit = int(x % 10);
        s.push_back('0' + digit);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
inline i128 S(i128 x)
{
    return x * (x + 1) / 2;
}
inline i128 sum_j(i128 t)
{
    return t * (t + 1) / 2;
}
inline i128 sum_j2(i128 t)
{
    return t * (t + 1) * (2 * t + 1) / 6;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long n_, w_;
        cin >> n_ >> w_;
        i128 n = (i128)n_;
        i128 w = (i128)w_;
        i128 total = S(n);
        i128 x = n;   
        i128 removed = 0;  
        while (x >= w) {
            i128 d = x / w;   
            i128 t = (x - w * d) / d + 1;
            i128 a = removed;
            i128 Tj = t;
            i128 sumj = sum_j(Tj);
            i128 sumj2 = sum_j2(Tj);
            i128 sum_y = Tj * a + d * sumj;
            i128 sum_y2 = Tj * a * a + 2 * a * d * sumj + d * d * sumj2;
            i128 sum_S_aj = (sum_y2 + sum_y) / 2;
            i128 contrib = Tj * S(n) - sum_S_aj;
            total += contrib;
            x -= t * d;
            removed = n - x;
        }
        print128(total);
        cout << '\n';
    }
    return 0;
}
