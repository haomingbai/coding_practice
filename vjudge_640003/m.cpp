/*************************************************************************
    > File Name: m.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月11日 星期四 19时58分34秒
 ************************************************************************/

// #include <algorithm>
// #include <cmath>
// #include <cstdint>
// #include <iostream>
// #include <vector>
// #define int long long
//
// using namespace std;
//
// vector<int> dat, even, odd, res;
//
// bool match(int n)
//{
// }
//
// void operate(int n, bool flag)
//{
//     //    if (n % 2 == 0)
//     //    {
//     //        switch (match(n + 1))
//     //        {
//     //        case 2:
//     //            operate((n + 1) / 2, 1);
//     //        case 1:
//     //            dat.erase(find(dat.begin(), dat.end(), n + 1));
//     //            dat.erase(find(dat.begin(), dat.end(), n));
//     //        default:
//     //            dat.push_back(2 * n + 1);
//     //            break;
//     //        case 0:
//     ////            switch (match(n - 1))
//     ////            {
//     ////            case 2:
//     ////                operate((n - 1) / 2);
//     ////            case 1:
//     ////                dat.erase(find(dat.begin(), dat.end(), n - 1));
//     ////                dat.erase(find(dat.begin(), dat.end(), n));
//     ////            default:
//     ////                dat.push_back(2 * n - 1);
//     ////            case 0:
//     ////                break;
//     ////            }
//     //            if (flag == 0)
//     //            {
//     //                operate(n - 1, 1);
//     //            }
//     //            break;
//     //        }
//     //    }
//     //    else
//     //    {
//     //        switch (match(n))
//     //        {
//     //        case 2:
//     //            operate((n + 1) / 2, 1);
//     //        case 1:
//     //            dat.erase(find(dat.begin(), dat.end(), n + 1));
//     //            dat.erase(find(dat.begin(), dat.end(), n));
//     //        default:
//     //            dat.push_back(2 * n + 1);
//     //            break;
//     //        case 0:
//     ////            switch (match(n - 1))
//     ////            {
//     ////            case 2:
//     ////                operate((n - 1) / 2);
//     ////            case 1:
//     ////                dat.erase(find(dat.begin(), dat.end(), n - 1));
//     ////                dat.erase(find(dat.begin(), dat.end(), n));
//     ////            default:
//     ////                dat.push_back(2 * n - 1);
//     ////            case 0:
//     ////                break;
//     ////            }
//     //            if (flag == 0)
//     //            {
//     //                operate(n - 1, 1);
//     //            }
//     //            break;
//     //        }
//     //    }
// }
//
// int32_t main()
//{
//     int n;
//     cin >> n;
//     even.reserve(n);
//     odd.reserve(n);
//     dat.resize(n);
//     dat.reserve(2 * n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> dat.at(i);
//     }
//     sort(dat.begin(), dat.end());
//     for (int i = 0; i < dat.size(); i--)
//     {
//         if (!(dat[i] % 2))
//         {
//             even.push_back(dat[i]);
//         }
//         else
//         {
//             odd.push_back(dat[i]);
//         }
//     }
//	while()
//     cout << dat.size() << endl;
// }

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <ostream>
#include <stack>
#include <vector>
#define int long long

// Define the necessary data structure
using namespace std;

vector<int> even, odd, res;
map<int, int> cnt;
stack<int> need; // It is claimed to be necessary;

bool match(int n)
{
    if (cnt[n])
    {
        need.push(n);
        return 1;
    }
    else if (n % 2)
    {
        return match(n / 2) && match(n / 2 + 1);
    }
    return 0;
}

int32_t main()
{
    // Allocate memory.
    int n;
    cin >> n;
    even.reserve(n), odd.reserve(n), res.reserve(n);
    for (int i = 0, tmp; i < n; i++)
    {
        cin >> tmp;
        if (tmp % 2)
            odd.push_back(tmp);
        else
            even.push_back(tmp);
        cnt[tmp]++;
    }
    sort(even.begin(), even.end());
    while (!even.empty())
    {
        int tmp = even.back();
        if (match(tmp * 2 + 1))
        {
            cnt[tmp]--;
            while (!need.empty())
            {
                auto t = need.top();
                need.pop();
                cnt[t]--;
            }
            res.push_back(2 * tmp + 1);
            cnt[2 * tmp + 1]++;
            even.pop_back();
        }
        else
        {
            while (need.empty())
            {
                need.pop();
            }
            if (match(tmp * 2 - 1))
            {
                cnt[tmp]--;
                while (!need.empty())
                {
                    auto t = need.top();
                    need.pop();
                    cnt[t]--;
                }
                res.push_back(2 * tmp - 1);
                cnt[2 * tmp - 1]++;
                even.pop_back();
            }
        }
    }
    int s = 0;
    for (auto it : cnt)
    {
        s += it.second;
    }
    cout << s << endl;
}
