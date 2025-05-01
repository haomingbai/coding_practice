#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef unsigned long long ull;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main()
{
    ull n, k, x, p;
    scanf("%lld%lld%lld%lld", &n, &k, &x, &p);
    ull *time_left = (ull *)malloc(sizeof(ull) * (k + 1)), *speed = (ull *)malloc(sizeof(ull) * (n));
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld", speed + i);
    }
    for (size_t i = 1; i <= k; i++)
    {
        scanf("%lld", time_left + i);
    }
    for (size_t i = 1; i <= k; i++)
    {
        ull t;
        scanf("%lld", &t);
        p = max(p, t - time_left[i]);
    }
    
    ull cnt = 0;
    
    for (size_t i = 0; i < n; i++)
    {
        if (p * speed[i] >= x)
        {
            cnt++;
        }
    }
    printf("%lld\n", cnt);
}