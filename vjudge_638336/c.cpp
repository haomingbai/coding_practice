/*************************************************************************
    > File Name: c.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月05日 星期五 12时23分07秒
 ************************************************************************/

#include <algorithm>
#include <ios>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long n, sum, mysum = 0;
    cin >> n >> sum;
    long long data[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> data[i];
        mysum += data[i];
    }
    // cout<<mysum<<'\n';
    if (mysum == sum)
    {
        cout << n << '\n';
        return 0;
	} else {
		n--;
	}
/*    sort(data, data + n);
    if (mysum < sum)
    {
        long long i;
        for (i = 1; i <= n; i++)
        {
            mysum -= data[i - 1];
            mysum += 10000;
            if (mysum >= sum)
            {
                break;
            }
        }
        n -= i;
    }
    else
    {
        while (n-- > 0)
        {
            mysum -= data[n];
            mysum -= 10000;
            if (mysum <= sum)
            {
                break;
            }
        }
    }*/
    cout << n << '\n';
    return 0;
}
