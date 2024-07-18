/*************************************************************************
    > File Name: f.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月09日 星期二 15时16分00秒
 ************************************************************************/

#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<long long> prime_list;

bool flag[10000101];

void init()
{
    prime_list.clear();
    prime_list.reserve(10000100);
    prime_list.push_back(2);
    for (long long i = 2; i < 10000100; i++)
    {
        if (!flag[i])
        {
            prime_list.push_back(i);
        }
        // cout << "begin" << endl;
        for (long long j = 0; j < prime_list.size() && i * prime_list.at(j) < 10000100; j++)
        {
            flag[i * prime_list.at(j)] = 1;
            if (i % prime_list.at(j) == 0)
                break;
        }
    }
}

vector<long long> prime_k;

map<long long, int> prime_p;

void dfs()
{
	long long p_new;
}

int main()
{
    init();
    long long p, x, k;
    cin >> p >> x >> k;
    prime_k.reserve(1000000);
    // Fractionalize p
    for (int i = 0; i < prime_list.size() && p > prime_list.at(i) * prime_list.at(i) && p > 1; i++)
    {
        if (p % prime_list.at(i) == 0)
        {
            prime_p.at(prime_list.at(i)) = 0;
            while (p % prime_list.at(i) == 0)
            {
                p /= prime_list.at(i);
                prime_p.at(prime_list.at(i))++;
            }
        }
    }
    for (int i = 0; i < prime_list.size() && k > prime_list.at(i) * prime_list.at(i) && p > 1; i++)
    {
        if (k % prime_list.at(i) == 0)
        {
            prime_k.push_back(prime_list.at(i));
            while (k % prime_list.at(i) == 0)
            {
                k /= prime_list.at(i);
            }
        }
    }
}
