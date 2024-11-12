#include <iostream>

using namespace std;

inline int count(long long n)
{
    int cnt = 0;
    while (n)
    {
        int dig = n % 10;
        n /= 10;
        if (dig == 1)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    long long n;
    cin >> n;
    long long cnt = 0;
    for (long long i = 1; i <= n; i++)
    {
        cnt += count(i);
    }
    cout << cnt << endl;
}