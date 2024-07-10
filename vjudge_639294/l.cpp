/*************************************************************************
    > File Name: l.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月10日 星期三 00时22分34秒
 ************************************************************************/

#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize(3, "Ofast", "inline")

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    string in;
    vector<int> v;
    cin >> in;
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == ')')
        {
            if (in[i - 1] == '(')
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(1);
            }
        }
    }
    reverse(v.begin(), v.end());
    long long ans = 1;
    for (long long cnt = 0; cnt < v.size(); cnt++)
    {
        if (v[cnt])
        {
            ans = ans * (cnt + 1) % 998244353;
        }
    }
    cout << ans << '\n';
}
