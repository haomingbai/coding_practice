#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int k;
        cin >> k;
        int y = 6;
        int x = k - 6;
        int cnt = 0;
        while (y >= x)
        {
            if (x > 0)
            {
                cnt++;
            }
            x++, y--;
        }
        cout << cnt << '\n';
    }
    
}