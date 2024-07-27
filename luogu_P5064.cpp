/*************************************************************************
    > File Name: luogu_P5064.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月22日 星期一 14时22分04秒
 ************************************************************************/

#include <algorithm>
#include <climits>
#include <cstring>
#include<iostream>
#include <vector>
#define int long long

using namespace std;

struct edge
{
	int origin, weight;
};

int dijkstra(int from, int to, int* storage, bool* flag, vector<vector<edge>> &edge)
{
	// cout << from << ' ' << to << endl;
	if (flag[to])
	{
		return storage[to];
	}
	flag[to] = 1;
	if (from == to)
	{
		storage[to] = 0;
		return 0;
	}
	for (auto it : edge[to])
	{
		storage[to] = min(dijkstra(from, it.origin, storage, flag, edge) + it.weight, storage[to]);
	}
	return storage[to];
}

int dijkstra(int from, int to, int *storage, vector<vector<edge>> &edge, int point_number)
{
}

signed main()
{
	int point_number, edge_number, start;
	cin >> point_number >> edge_number >> start;
	start--;
	vector<vector<edge>> edge(point_number + 1);
	for (int i = 0, x, y, w; i < edge_number; i++)
	{
		cin >> x >> y >> w;
		x--, y--;
		// edge[x].push_back({y, w});
		edge[y].push_back({x, w});
	}
	int* storage = new int[point_number + 1]();
	for (int i = 0; i <= point_number; i++)
	{
		storage[i] = LLONG_MAX;
	}
	for (int i = 0; i < point_number; i++)
	{
		edge[point_number].push_back({i, 1});
	}
	// memset(storage, 0x3f, sizeof(int) * (point_number + 1));
	bool* flag = new bool[point_number + 1]();
	// flag[start] = !flag[start];
	dijkstra(start, point_number, storage, edge, point_number + 1);
	for (int i = 0; i < point_number; i++)
	{
		cout << storage[i] << ' ';
		// cout << dijkstra(start, i, storage, flag, edge) << ' ';
	}
	cout << endl;
}
