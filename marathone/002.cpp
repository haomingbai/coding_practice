#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[7] = {0, 1, 2, 3, 4, 5, 6};
    int pos = 0;
    int res = 0;
    while (n--)
    {
        a[pos]++;
        res += a[pos];
        pos++;
        pos %= 7;
    }
    cout << res << endl;
}