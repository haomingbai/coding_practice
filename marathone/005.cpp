#include <iostream>

using namespace std;

int main()
{
    int k, num;
    cin >> num >> k;
    auto flag = new int[10]();
    for (size_t i = 1; i <= 10; i++)
    {
        auto x = k * i;
        x %= 10;
        if (!flag[x])
        {
            flag[x] = i;
        }
    }
    if (num == 0)
    {
        cout << 0 << endl;
    }
    else if (flag[num % 10] && num >= k * flag[num % 10])
    {
        cout << flag[num % 10] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}