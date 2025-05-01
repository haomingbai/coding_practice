/*************************************************************************
    > File Name: j.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月05日 星期五 14时19分29秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <pthread.h>

using namespace std;

int P_S[9 * 1001], *P = P_S, S_S[9 * 1001], *S = S_S, M_S[9 * 1001], *M = M_S, Z_S[7 * 1001], *Z = Z_S, r[1001],
                   appear[1001], pair_num[1001];
char SRC_S[29 * 1001], *src = SRC_S;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> src;
        for (int j = 0; j < 28; j += 2)
        {
            switch (src[j + 1])
            {
            case 'p': {
                P[src[j] - '0']++;
                if (P[src[j] - '0'] == 3)
                {
                    goto end_loop;
                }
                if (P[src[j] - '0'] == 1 && (src[j] == '1' || src[j] == '9'))
                {
                    appear[i]++;
                }
                if (P[src[j] - '0'] == 2)
                {
                    pair_num[i]++;
                }
                break;
            }
            case 's': {
                S[src[j] - '0']++;
                if (S[src[j] - '0'] == 3)
                {
                    goto end_loop;
                }
                if (S[src[j] - '0'] == 1 && (src[j] == '1' || src[j] == '9'))
                {
                    appear[i]++;
                }
                if (S[src[j] - '0'] == 2)
                {
                    pair_num[i]++;
                }
                break;
            }
            case 'm': {
                M[src[j] - '0']++;
                if (M[src[j] - '0'] == 3)
                {
                    goto end_loop;
                }
                if (M[src[j] - '0'] == 1 && (src[j] == '1' || src[j] == '9'))
                {
                    appear[i]++;
                }
                if (M[src[j] - '0'] == 2)
                {
                    pair_num[i]++;
                }
                break;
            }
            case 'z': {
                Z[src[j] - '0']++;
                if (Z[src[j] - '0'] == 3)
                {
                    goto end_loop;
                }
                if (Z[src[j] - '0'] == 1)
                {
                    appear[i]++;
                }
                if (Z[src[j] - '0'] == 2)
                {
                    pair_num[i]++;
                }
            }
            }
        }
        if (appear[i] >= 13)
        {
            r[i] = 1;
        }
        else if (pair_num[i] == 7)
        {
            r[i] = 2;
        }
    end_loop:
        P += 9, S += 9, M += 9, Z += 7, src += 14;
    }
    for (int i = 0; i < T; i++)
    {
        switch (r[i])
        {
        case 0:
            printf("Otherwise\n");
            break;
        case 1:
            printf("Thirteen Orphans\n");
            break;
        case 2:
            printf("7 Pairs\n");
            break;
        }
    }
}
