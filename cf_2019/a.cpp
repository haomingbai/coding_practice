#include <iostream>
#include <cstdint>
#include <vector>
#include <array>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<uint64_t> dat(n);
        size_t maxval(0), maxpos(-1);
        for (size_t i = 0; i < n; i++)
        {
            cin >> dat[i];
            if (dat[i] > maxval)
            {
                maxval = dat[i];
                maxpos = i;
            }
            else if (dat[i] == maxval && maxpos % 2)
            {
                maxpos = i;
            }
        }
        if (n % 2)
        {
            if (maxpos % 2)
            {
                cout << (n / 2 + maxval) << endl;
            }
            else
            {
                cout << (n / 2 + 1 + maxval) << endl;
            }
        }
        else
        {
            cout << (n / 2 + maxval) << endl;
        }
        
    }
}