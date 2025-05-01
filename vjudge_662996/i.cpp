#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

void process(string &str)
{
    int n = str.length();
    // Case 1, begin even and end even and char at begin equals to char at end.
    if (str.front() == str.back())
    {
        size_t cnt(0);
        char x = str.front();
        while (str[cnt] == x)
        {
            cnt++;
        }
        string str_n = str.substr(0, cnt);
        str = str.substr(cnt);
        str.append(str_n);
    }
    // cout << str << endl;
    char x = 0;
    size_t cnt{1};
    for (size_t i = 0; i <= n; i++)
    {
        if (str[i] == x)
        {
            cnt++;
        }
        else if (cnt && (cnt % 2 == 0) && str[i] != str.front())
        {
            cnt--;
            string str_n = str.substr(0, i - cnt);
            str = str.substr(i - cnt);
            str.append(str_n);
            return;
        }
        else
        {
            cnt = 1;
            x = str[i];
        }
    }
    return;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        process(str);
        size_t cnt{1}, res = 0;
        char x = 0;
        // cout << str << endl;
        for (size_t i = 0, n = str.length(); i < str.length(); i++)
        {
            if (str[i] == x)
            {
                cnt++;
            }
            else
            {
                res += cnt / 2;
                x = str[i];
                cnt = 1;
            }
        }
        if (cnt != 1)
        {
            res += cnt / 2;
        }
        cout << res << '\n';
    }
}