#include <cstddef>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    size_t *dat = new size_t[str.length()]();
    bool *flag = new bool[256]();
    flag[dat[0]] = 1;
    dat[0] = 1;
    size_t left = 0, right = 0;
    size_t res = 1;
    while (right < str.length())
    {
        if (left > right)
        {
            right++;
            continue;
        }
        else if (flag[str[right]])
        {
            while (flag[str[right]])
            {
                flag[str[left]] = 0;
                left++;
            }
            flag[str[right]] = 1;
            right++;
        }
        else
        {
            flag[str[right]] = 1;
            res = max(res, right - left + 1);
            right++;
        }
    }
    cout << res << endl;
}