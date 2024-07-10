/*************************************************************************
    > File Name: d.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月08日 星期一 13时50分18秒
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include <ios>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

long long prime_list[] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,  67,
                          71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,
                          167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269,
                          271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383,
                          389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
                          503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619,
                          631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751,
                          757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881,
                          883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

int prime_list_max[] = {
    524288, 531441, 390625, 823543, 161051, 371293, 83521,  130321, 279841, 707281, 923521, 50653,  68921,  79507,
    103823, 148877, 205379, 226981, 300763, 357911, 389017, 493039, 571787, 704969, 912673, 10201,  10609,  11449,
    11881,  12769,  16129,  17161,  18769,  19321,  22201,  22801,  24649,  26569,  27889,  29929,  32041,  32761,
    36481,  37249,  38809,  39601,  44521,  49729,  51529,  52441,  54289,  57121,  58081,  63001,  66049,  69169,
    72361,  73441,  76729,  78961,  80089,  85849,  94249,  96721,  97969,  100489, 109561, 113569, 120409, 121801,
    124609, 128881, 134689, 139129, 143641, 146689, 151321, 157609, 160801, 167281, 175561, 177241, 185761, 187489,
    192721, 196249, 201601, 208849, 212521, 214369, 218089, 229441, 237169, 241081, 249001, 253009, 259081, 271441,
    273529, 292681, 299209, 310249, 316969, 323761, 326041, 332929, 344569, 351649, 358801, 361201, 368449, 375769,
    380689, 383161, 398161, 410881, 413449, 418609, 426409, 434281, 436921, 452929, 458329, 466489, 477481, 491401,
    502681, 516961, 528529, 537289, 546121, 552049, 564001, 573049, 579121, 591361, 597529, 619369, 635209, 654481,
    657721, 674041, 677329, 683929, 687241, 703921, 727609, 734449, 737881, 744769, 769129, 776161, 779689, 786769,
    822649, 829921, 844561, 863041, 877969, 885481, 896809, 908209, 935089, 942841, 954529, 966289, 982081, 994009};

long long **lst;

vector<long long> remain;

long long res[1000001];

int main()
{
    remain.reserve(1000001);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long T;
    cin >> T;
    for (long long i = 0; i < T; i++)
    {
        long long n;
        cin >> n;
        remain.clear();
        lst = new long long *[168]();
        for (long long j = 0; j < 168; j++)
        {
            lst[j] = new long long[n]();
        }
        for (long long j = 0, tmp; j < n; j++)
        {
            // cout << j << endl;
            cin >> tmp;
            for (long long k = 0; k < 168; k++)
            {
                int cnt = 0, flag = 0;
                /*while (tmp % prime_list[k] == 0)
                {
                    lst[k][j]++;
                    flag = 1;
                    tmp /= prime_list[k];
                }
                if (flag == 1)
                {
                    cnt++;
                    flag = 0;
                }*/
                if (tmp % prime_list[k] == 0)
                {
                    lst[k][j] = gcd(tmp, prime_list_max[k]);
					cnt++;
					tmp /= lst[k][j];
                }
                if (tmp == 1 && cnt == 6)
                {
                    cnt = 0;
                    break;
                }
            }
            if (tmp != 1)
            {
                remain.push_back(tmp);
            }
        }
        for (long long j = 0; j < 168; j++)
        {
            sort(lst[j], lst[j] + n);
        }
        n--;
        long long tmp = 1;
        for (auto it : remain)
        {
            tmp *= it;
            tmp %= 998244353;
        }
        while (n >= 0)
        {
            for (long long j = 0; j < 168; j++)
            {
				/*
                for (long long k = 0; k < lst[j][n]; k++)
                {
                    tmp *= ;
                }
				*/
				tmp *= lst[j][n] ? lst[j][n] : 1;
                tmp %= 998244353;
            }
            n--;
            res[i] += tmp;
            tmp = 1;
            res[i] %= 998244353;
        }
        cout << res[i] << '\n';
        for (long long j = 0; j < 168; j++)
        {
            delete[] lst[j];
        }
        delete[] lst;
    }
}