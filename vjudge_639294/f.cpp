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

void dfs ();

int main()
{
    init();
    long long p, x, k;
    // cin >> p >> x >> k;
}
