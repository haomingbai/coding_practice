/*************************************************************************
    > File Name: f.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月03日 星期三 13时56分16秒
 ************************************************************************/

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <vector>

std::vector<std::vector<long long>> res;
size_t freq[1000000000];

struct query
{
    size_t index;
    long long *left;
    long long *right;
    bool operator<(query b)
    {
        return right < b.right;
    }
    bool operator>(query b)
    {
        return right > b.right;
    }
    bool operator<=(query b)
    {
        return right <= b.right;
    }
    bool operator>=(query b)
    {
        return right >= b.right;
    }
};

int main()
{
    size_t T;
    scanf("%ld", &T);
    long long *dat, *pros;
    res.resize(T);
    for (size_t i = 0, N, blk_size, Q, blk_num, left, right; i < T; i++)
    {
        // First fetch data;
        long long max_val = 0;
        scanf("%ld", &N);
        dat = new long long[N];
        for (size_t j = 0; j < N; j++)
        {
            scanf("%lld", dat + j);
            max_val = std::max(dat[j], max_val);
        }
        // Then fetch queries
        blk_size = sqrtl(N);
        blk_num = (N - 1) / blk_size;
        if (N % blk_size)
        {
            blk_num++;
        }
        std::vector<query> *q = new std::vector<query>[blk_num];
        scanf("%ld", &Q);
        res[i].resize(Q);
        for (size_t j = 0, tmp; j < Q; j++)
        {
            scanf("%ld %ld", &left, &right);
            tmp = left / blk_size;
            q[(left - 1) / blk_size].push_back({j, dat + left - 1, dat + right - 1});
        }
        for (size_t j = 0; j < blk_num; j++)
        {
            std::sort(q[j].begin(), q[j].end());
        }
        memset(freq, 0, 8 * (max_val + 1));
        // auto freq = new size_t[max_val*2+1]();
        auto pt_left = dat;
        auto pt_right = dat;
        freq[*dat] = 1;
        long long s = *dat;
        for (size_t j = 0; j < blk_num; j++)
        {
            // printf("f**k\n");
            for (auto ite : q[j])
            {
                // printf("f*k\n");
                while (ite.right > pt_right)
                {
                    pt_right++;
                    if (freq[*pt_right] == 0)
                    {
                        s += *pt_right;
                    }
                    freq[*pt_right]++;
                }
                while (ite.right < pt_right)
                {
                    if (freq[*pt_right] == 1)
                    {
                        s -= *pt_right;
                    }
                    freq[*pt_right]--;
                    pt_right--;
                }
                while (ite.left > pt_left)
                {
                    if (freq[*pt_left] == 1)
                    {
                        s -= *pt_left;
                    }
                    freq[*pt_left]--;
                    pt_left++;
                }
                while (ite.left < pt_left)
                {
                    pt_left--;
                    if (freq[*pt_left] == 0)
                    {
                        s += *pt_left;
                    }
                    freq[*pt_left]++;
                }
                res[i].at(ite.index) = s;
            }
        }
        delete[] dat;
    }
    for (size_t i = 0, N, blk_size, Q, blk_num, left, right; i < T; i++)
    {
        for (auto it : res[i])
        {
            printf("%lld\n", it);
        }
    }
}
