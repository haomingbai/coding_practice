#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        // avaavavaavaavava
        bool flag = 1;
        for (auto it = S.begin(); it <= S.end() - 5;)
        {
            cout << *it << it - S.begin() << endl;
            if (*it == 'a' && *(it + 1) == 'v' && *(it + 2) == 'a')
            {
                it += 3;
                switch (*it)
                {
                case 'a':
                    break;
                case 'v':
                    /* code */
                    if (*(it + 1) == 'a')
                    {
                        it += 2;
                        break;
                    }
                case ' ':
                    goto output;
                default:
                    flag = 0;
                    goto output;
                }
            }
            else
            {
                flag = 0;
                break;
            }
        }
    output:
        if (flag)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}