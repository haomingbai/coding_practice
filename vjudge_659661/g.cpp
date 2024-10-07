#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

template <typename T1, typename T2>
class frac : public pair<T1, T2>
{
public:
    bool operator==(frac<T1, T2> b)
    {
        auto x1 = __gcd(this->first, this->second);
        auto x2 = __gcd(b.first, b.second);
        if (first / x1 == b.first / x2 && second / x1 == b.second / x2)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int z;
    cin >> z;
    while (z--)
    {
        /* code */
    }
    
}