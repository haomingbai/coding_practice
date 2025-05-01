#include <iostream>

using namespace std;

int pt[1000][10];

int main ()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> pt[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int select = -1;
        for (int j = 0; j < n; j++)
        {
            bool flag = 1;
            for (int k = 0; k < m; k++)
            {
                if (pt[i][k] >= pt[j][k])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                select = j;
                break;
            }
        }
        cout << select + 1 << endl;
    }
}