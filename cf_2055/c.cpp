#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        string path;
        cin >> n >> m;
        cin >> path;
        size_t pos(0); // The pos to begin
        if (path.front() == 'D')
        {
            pos = 0;
        }
        else if (path.back() == 'D')
        {
            pos = path.length() - 1;
        }
        else
        {
            for (size_t i = 1; i < path.length() - 1; i++)
            {
                if (path[i] == 'D')
                {
                    pos++;
                }

                if (path[i] == 'D' && path[i + 1] == 'D')
                {
                    break;
                }
            }
        }
    }
}