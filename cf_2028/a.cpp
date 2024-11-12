#include <functional>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int x(0), y(0);
        bool flag = false;

        vector<pair<int, int>> path;
        path.reserve(10);
        for (auto &&i : s)
        {
            switch (i)
            {
            case 'N':
                y++;
                break;

            case 'E':
                x++;
                break;

            case 'S':
                y--;
                break;

            case 'W':
                x--;
                break;

            default:
                break;
            }
            if (x == a && y == b)
            {
                flag = true;
                break;
            }
            path.emplace_back(x, y);
        }
        if (x == 0 && y == 0)
        {
            goto output;
        }
        
        for (auto &&i : path)
        {
            auto arem = a - i.first, brem = b - i.second;
            if (x == 0)
            {
                if (brem % y == 0 && brem * y > 0 && arem == 0)
                {
                    flag = true;
                    break;
                }
            }
            else if (y == 0)
            {
                if (arem % x == 0 && arem * x > 0 && brem == 0)
                {
                    flag = true;
                    break;
                }
            }
            else if (arem % x == 0 && arem * x > 0 && brem % y == 0 && brem * y > 0 && arem * y == brem * x)
            {
                flag = true;
                break;
            }
        }

    output:
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}