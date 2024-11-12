#include <iostream>
#include <vector>

using namespace std;

auto calc()
{
    vector<vector<int>> res(31);
    for (size_t i = 0; i < 31; i++)
    {
        res[i].resize(10);
        for (size_t j = 0; j < 10; j++)
        {
            res[i][j] = 0;
        }
    }
    for (size_t i = 0, x = 1; i < 31; i++)
    {
        int tmp = x;
        while (tmp)
        {
            int ttmp = tmp % 10;
            tmp /= 10;
            res[i][ttmp]++;
        }
        x *= 2;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    auto backup = n;
    vector<int> de(10);
    for (auto &&i : de)
    {
        i = 0;
    }

    while (n)
    {
        auto x = n % 10;
        n /= 10;
        de[x]++;
    }
    auto flag = false;
    auto dat = calc();
    //        for (size_t i = 0; i < 5; i++)
    //        {
    //            for (size_t j = 0; j < 10; j++)
    //            {
    //                cout << dat[i][j] << ' ';
    //            }
    //            cout << endl;
    //        }
    //    for (size_t i = 0; i < 10; i++)
    //    {
    //        cout << de[i] << ' ';
    //        cout << endl;
    //    }

    for (auto i = 0; i < 31; i++)
    {
        auto fflag = true;
        for (auto j = 0; j < 10; j++)
        {
            if (dat[i][j] != de[j])
            {
                fflag = false;
                break;
            }
        }
        if (fflag)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }
}