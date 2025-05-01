/*************************************************************************
    > File Name: b.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月23日 星期二 23时08分55秒
 ************************************************************************/

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#define int long long

using namespace std;

signed main(signed argc, char **argv)
{
    int T;
    cin >> T;
    while (T--)
    {
        map<int, int> dat;
        int n, m;
        cin >> n >> m;
        for (int i = 0, tmp; i < n; i++)
        {
            cin >> tmp;
            dat[tmp]++;
        }
        int sto = 0;
        for (auto iter = dat.begin(); iter != dat.end(); iter++)
        {
            auto it_next = iter;
            it_next++;
            auto key1 = iter->first, val1 = iter->second, key2 = (int)-1, val2 = (int)0;
            int opt1 = 0, opt2 = 0;
            if (it_next != dat.end())
            {
                key2 = it_next->first, val2 = it_next->second;
                if (abs(key2 - key1) <= 1)
                {
                    int num1 = min(val1, m / key1);
                    int num2 = min(val2, m / key2);
                    opt1 = num1 * key1;
                    int use2 = min((m - key1 * num1) / key2, num2), use1 = num1;
                    while (use1 > 0)
                    {
                        while (key1 * use1 + key2 * (use2 + 1) <= m && use2 < num2)
                        {
                            use2++;
                        }
                        opt1 = max(opt1, key1 * use1 + key2 * use2);
                        use1--;
                    }
                    opt2 = num2 * key2;
                }
                else
                {
                    opt1 = min((m / key1), val1);
                    opt1 *= key1;
                    opt2 = min((m / key2), val2);
                    opt2 *= key2;
                }
            }
            else
            {
                opt1 = min((m / key1), val1);
                opt1 *= key1;
            }
            sto = max({sto, opt1, opt2});
        }
        cout << sto << '\n';
    }
}

/*
#include <algorithm>
#include <iostream>
#include <map>
#define int long long

using namespace std;

signed main(signed argc, char **argv)
{
    int T;
    cin >> T;
    while (T--)
    {
        map<int, int> dat;
        int n, m;
        cin >> n >> m;
        for (int i = 0, tmp; i < n; i++)
        {
            cin >> tmp;
            dat[tmp]++;
        }
        int sto = 0;
        for (auto iter = dat.begin(); iter != dat.end(); iter++)
        {
            int key1 = iter->first, val1 = iter->second;
            auto it_next = iter;
            it_next++;
            int opt1 = 0, opt2 = 0;

            if (it_next != dat.end())
            {
                int key2 = it_next->first, val2 = it_next->second;
                if (abs(key2 - key1) <= 1)
                {
                    int num1 = min(val1, m / key1);
                    int num2 = min(val2, m / key2);
                    opt1 = num1 * key1;
                    int use2 = min((m - key1 * num1) / key2, num2), use1 = num1;
                    while (use1 > 0)
                    {
                        while (key1 * use1 + key2 * (use2 + 1) <= m && use2 < num2)
                        {
                            use2++;
                        }
                        opt1 = max(opt1, key1 * use1 + key2 * use2);
                        use1--;
                    }
                    opt2 = num2 * key2;
                }
            }
            opt1 = max(opt1, min(m / key1, val1) * key1);
            sto = max({sto, opt1, opt2});
        }
        cout << sto << '\n';
    }
}
*/
