/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月03日 星期三 19时03分03秒
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include <iterator>

using namespace std;

long pool[20 * 400000], *pt = pool, pool_sto[20 * 4000], *pts = pool_sto;
long poolA[20 * 4000], *ptA = poolA, pool_stoB[20 * 4000], *ptB = pool_stoB;
bool pool_flg[20 * 4000], *ptf = pool_flg;

int solve();

long r[30], *x = r;

int main()
{
    // ios::sync_with_stdio(false), cin.tie(nullptr);
    while (solve())
        ;
    // for_each(r, x, [](long x) { printf("%ld\n", x); });
}

int solve()
{
    long N, K;
    if (scanf("%ld %ld", &N, &K) == EOF)
        return 0;
    // printf("hello\n");
    long *data = pt,*storage=pts,*A=ptA,*B=ptB;
	bool*flag=ptf;
    pt += N,ptf+=K,pts+=K,ptA+=K,ptB+=K;
	long unsatisfied = K,min_len = K;
    //long *A = new long[K], *B = new long[K], min_len{K}, *storage = new long[K](), unsatisfied = K;
    //bool found = 0, *flag = new bool[K]();
    for (long i{0}; i < N; i++)
    {
        scanf("%ld", data + i);
        data[i]--;
    }
    for (long i{0}; i < K; i++)
    {
        scanf("%ld %ld", A + i, B + i);
        if (A[i] <= 0)
        {
            flag[A[i]] = 1;
            unsatisfied--;
            min_len--;
			A[i] = 0;
        }
		if(B[i]<0)
		{
			printf("-1\n");
			return -1;
		}
    }
    if (K > N)
    {
        // *(x++) = -1;
        printf("-1\n");
        return 1;
    }
    for (int i = 0; i < min_len; i++)
    {
        storage[data[i]]++;
        if (flag[data[i]] == 0 && storage[data[i]] == A[data[i]])
        {
            flag[data[i]] = 1;
            unsatisfied--;
        }
        else if (flag[data[i]] == 1 && storage[data[i]] > B[data[i]])
        {
            flag[data[i]] = 0;
            unsatisfied++;
        }
    }
    if (!unsatisfied)
    {
        *(x)++ = min_len;
        return 1;
    }
    long left = 0, right = min_len - 1;
    while (min_len < N)
    {
        if (left == 0)
        {
            for (long i = 0; i < N - min_len; i++)
            {
                storage[data[left]]--;
                if (flag[data[left]] == 0 && (storage[data[left]] == B[data[left]]))
                {
                    unsatisfied--;
                    flag[data[left]] = 1;
                }
                else if (flag[data[left]] == 1 && (storage[data[left]] < A[data[left]]))
                {
                    unsatisfied++;
                    flag[data[left]] = 0;
                }
                left++;
                right++;
                storage[data[right]]++;
                if (flag[data[right]] == 0 && (storage[data[right]] == A[data[right]]))
                {
                    unsatisfied--;
                    flag[data[right]] = 1;
                }
                else if (flag[data[right]] == 1 && (storage[data[right]] > B[data[right]]))
                {
                    unsatisfied++;
                    flag[data[right]] = 0;
                }
                if (!unsatisfied)
                {
                    //*(x++) = min_len;
                    printf("%ld\n", min_len);
                    return 1;
                }
            }
            left--;
            storage[data[left]]++;
            if (flag[data[left]] == 0 && (storage[data[left]] == A[data[left]]))
            {
                unsatisfied--;
                flag[data[left]] = 1;
            }
            else if (flag[data[left]] == 1 && (storage[data[left]] > B[data[left]]))
            {
                unsatisfied++;
                flag[data[left]] = 0;
            }
            min_len++;
            if (!unsatisfied)
            {
                //*(x++) = min_len;
                printf("%ld\n", min_len);
                return 1;
            }
        }
        else
        {
            for (long i = 0; i < N - min_len; i++)
            {
                storage[data[right]]--;
                if (flag[data[right]] == 0 && (storage[data[right]] == B[data[right]]))
                {
                    unsatisfied--;
                    flag[data[right]] = 1;
                }
                if (flag[data[right]] == 1 && (storage[data[right]] < A[data[right]]))
                {
                    unsatisfied++;
                    flag[data[right]] = 0;
                }
                left--;
                right--;
                storage[data[left]]++;
                if (flag[data[left]] == 0 && (storage[data[left]] == A[data[left]]))
                {
                    unsatisfied--;
                    flag[data[left]] = 1;
                }
                if (flag[data[left]] == 1 && (storage[data[left]] > B[data[left]]))
                {
                    unsatisfied++;
                    flag[data[left]] = 0;
                }
                if (!unsatisfied)
                {
                    //*(x++) = min_len;
                    printf("%ld", min_len);
                    return 1;
                }
            }
            right++;
            storage[data[right]]++;
            if (flag[data[right]] == 0 && (storage[data[right]] == A[data[right]]))
            {
                unsatisfied--;
                flag[data[right]] = 1;
            }
            if (flag[data[right]] == 1 && (storage[data[right]] > B[data[right]]))
            {
                unsatisfied++;
                flag[data[right]] = 0;
            }
            min_len++;
            if (!unsatisfied)
            {
                //*(x++) = min_len;
                printf("%ld\n", min_len);
                return 1;
            }
        }
    }
    //*(x++) = -1;
    printf("-1\n");
    return 1;
}
