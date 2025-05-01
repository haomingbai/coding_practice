#include <iostream>
#include <algorithm>

using namespace std;

const int P[] = {648, 328, 198, 88, 28, 6, 1}, F[] = {388, 198, 128, 58, 28, 18, 8}, COLNUM = 7;

int main()
{
    int n;
    cin >> n;
    auto a = new int[7][2001]();
    a[0][0] = 0, a[0][648] = 388;
    for (size_t i = 1; i < COLNUM; i++)
    {
        for (size_t j = 0; j <= n; j++)
        {
            // cout << a[i][j] << endl;
            if (j >= P[i])
            {
                a[i][j] = max(a[i - 1][j], a[i - 1][j - P[i]] + F[i]);
            }
            else
            {
                a[i][j] = a[i - 1][j];
            }
            
        }
    }
    int maxval = 0;
    for (size_t i = 0; i <= n; i++)
    {
        if (a[COLNUM - 1][i] > maxval)
        {
            maxval = a[COLNUM - 1][i];
        }
    }

    int r = n * 10;
    r += maxval;
    cout << r << endl;
}