#include <iostream>
#include <string>

using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    if (n < 1 + k)
    {
        for (size_t i = 1; i < n; i++)
        {
            cout << i << ' ';
        }
        cout << n << endl;
        return 0;
    }

    auto visited = new bool[n + 1]();
    string output;

    for (size_t i = 1; i <= k; i++)
    {
        int j = i;
        while (j <= n)
        {
            string tmp = to_string(j);
            output.append(tmp + " ");
            j += k;
        }
        
    }
    
    while (output.back() == ' ')
    {
        output.pop_back();
    }
    
    cout << output;
}