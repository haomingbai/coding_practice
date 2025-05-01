/*************************************************************************
	> File Name: d.cpp
	> Author: Haoming Bai
	> Mail: haomingbai@hotmail.com
	> Created Time: 2024年07月01日 星期一 21时34分00秒
 ************************************************************************/

#include <ios>
#include <iostream>
#include <list>

using namespace std;

struct node {
	int id;
	int value;
	list<node*>* leaves;
	int parent;
	node()
		: value(0)
	{
		leaves = new list<node*>();
	}
	node(int id, int parent)
		: id(id)
		, parent(parent)
		, value(0)
	{
		leaves = new list<node*>();
	}
};

void build_tree(int* path[2], node** dat, int n)
{
	auto& x = (*dat);
	dat++;
	for (int i = 0; i < n - 1; i++) {
		if (path[i][1] == x->id) {
			*(dat) = new node(path[i][0], path[i][1]);
			x->leaves->push_back(*dat);
			dat++;
		} else if (path[i][0] == x->id) {
			*(dat) = new node(path[i][1], path[i][0]);
			x->leaves->push_back(*dat);
			dat++;
		}
	}
	for (auto it : *(x->leaves)) {
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	node** dat = new node*[n];
	auto path = new int[n - 1][2];
	dat[0] = new node(1, 0);
	for (int i = 0; i < n - 1; i++) {
		cin >> path[i][0] >> path[i][1];
	}
}
