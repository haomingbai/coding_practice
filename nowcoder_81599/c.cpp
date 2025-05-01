/*************************************************************************
    > File Name: c.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月25日 星期四 12时38分46秒
 ************************************************************************/

#include <utility>
#pragma GCC optimize("O3")
#include <iostream>
#include <set>
// #include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *dat = new int[n + 1];
        set<int> diff;
        // vector<int> diff;
        for (int i = 0; i < n; i++)
        {
            cin >> dat[i + 1];
            if (dat[i + 1] != i + 1)
            {
                diff.insert(dat[i + 1]);
            }
        }
        int cnt = 0, el2 = 0;
        for (auto it : diff)
        {
            if (dat[dat[it]] == it)
                el2++;
            else if (dat[dat[dat[it]]] == it)
                cnt++;
        }
		// cout << diff.size() << endl;
        cnt /= 4, el2 /= 2;
        // cout << el2 << cnt << endl;
        el2 /= 2;
        int offset = 4 * el2 - 4 * cnt;
        // cout << el2 << cnt << endl;
        cnt += el2;
        if ((int)diff.size() - offset - 1 >= 0)
		{
			// cout << ((int)diff.size() - 1 - offset) << endl;
            cnt += ((int)diff.size() - offset - 1) % 3 ? ((int)diff.size() - 1 - offset) / 3 + 1 : ((int)diff.size() - offset - 1) / 3;
		}
        cout << cnt << '\n';
    }
}
