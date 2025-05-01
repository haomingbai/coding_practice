#include <iostream>
#include <string>

using namespace std;

inline bool judge(char x)
{
    if (x == '(' || x == ')')
    {
        return true;
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        bool res = true;
        bool flag = true;
        cin >> str;
        string nstr = "";

        for (int i = str.length() - 1; i > 0; i--)
        {
            if (str[i] == str[i - 1])
            {
                nstr = str.substr(2 * i - str.length());
                str = str.substr(0, 2 * i - str.length());
            }
        }
        // cout << str.length() << endl;
        // cout << nstr.length() << endl;
        // str
        if (str.length())
        {
            for (size_t i = 1; i < str.length() / 2; i++)
            {

                if (judge(str[i]) == judge(str[i - 1]))
                {
                    flag = false;
                }
                if (judge(str[str.length() - i]) == judge(str[str.length() - i - 1]))
                {
                    flag = false;
                }
                if ((judge(str[i]) != judge(str[str.length() - i - 1])) ||
                    (judge(str[i - 1]) != judge(str[str.length() - i])))
                {
                    flag = false;
                }
            }
        }
        if (nstr.length())
        {
            str = nstr;
            for (size_t i = 1; i < str.length() / 2; i++)
            {
                if (judge(str[i]) == judge(str[i - 1]))
                {
                    flag = false;
                }
                if (judge(str[str.length() - i]) == judge(str[str.length() - i - 1]))
                {
                    flag = false;
                }
                if ((judge(str[i]) != judge(str[str.length() - i])) ||
                    (judge(str[i - 1]) != judge(str[str.length() - i - 1])))
                {
                    flag = false;
                }
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }
}