#include <iostream>
#include <vector>

using namespace std;

long long pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

int main()
{
    long long n;
    cin >> n;
    long long bak = n;

    vector<int> dat(10);
    for (auto &&i : dat)
    {
        i = n % 10;
        n /= 10;
    }

    long long cnt = 0;

    // ref[i] indicates the number of 1 from 0 to 10**i (10**i is not included).
    vector<long long> ref;
    ref.reserve(10);

    ref.push_back(0);
    for (size_t i = 1; i < 10; i++)
    {
        auto x = ref.back(), restmp = 0ll;
        restmp = x * 10;
        restmp += pow10[i - 1];
        ref.push_back(restmp);
    }

    for (size_t i = 0; i < 10; i++)
    {
        int tmp = dat[i];

        if (tmp == 1)
        {
            cnt += bak % pow10[i] + 1;
        }
        
        while (tmp--)
        {
            cnt += ref[i];
            if (tmp == 1)
            {
                cnt += pow10[i];
            }
        }
    }
    cout << cnt << endl;
}