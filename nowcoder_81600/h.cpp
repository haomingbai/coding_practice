/*************************************************************************
    > File Name: h.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月30日 星期二 13时45分53秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int dfs(int pos, int *record, vector<set<int>> &graph)
{
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> dat(n);
    for (int i = 0; i < m; i++)
    {
        int j, k;
        cin >> j >> k;
        j--, k--;
        dat[j].insert(k), dat[k].insert(j);
    }
    auto record = new int[n]();
}
