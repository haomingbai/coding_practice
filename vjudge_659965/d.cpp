#include <iostream>
#include <map>
#include <cmath>

using namespace std;

float Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;
    x2 = number * 0.5F;
    y   = number;
    i   = * ( long * ) &y;   // evil floating point bit level hacking
    i   = 0x5f3759df - ( i >> 1 ); // what the fuck?
    y   = * ( float * ) &i;
    y   = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
    // y   = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be removed
    return 1/y;
}  

bool judge(long long to_process, long long curr_wait)
{
    long long max = (long long)Q_rsqrt(to_process) + 1;
    // long long max = 1e9;
    if (to_process % curr_wait == 0)
    {
        to_process /= curr_wait;
    }
    if (to_process % curr_wait == 0)
    {
        return true;
    }
    if (curr_wait > max)
    {
        return false;
    }
    // cout << curr_wait << endl;
    return judge(to_process, curr_wait + 1);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        cout << (judge(n, 2) ? "yes" : "no") << '\n';
    }
}