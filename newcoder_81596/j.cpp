/*************************************************************************
    > File Name: j.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月16日 星期二 12时46分14秒
 ************************************************************************/

#include <ios>
#include <iostream>
// #include <tuple>
#define int long long

using namespace std;

// int tree[800000][4]; // 0 as U, 1, as D, 2, as L, 3 as R

/*
void make_tree(int (*src)[4], int (*tree)[4], int node, int start, int end)
{
    if (start == end)
    {
        tree[node][0] = src[start][0];
        tree[node][1] = src[start][1];
        tree[node][2] = src[start][2];
        tree[node][3] = src[start][3];
    }
    else
    {
        int mid = (start + end) / 2;
        int node_left = 2 * node + 1;
        int node_right = 2 * node + 2;
        make_tree(src, tree, node_left, start, mid);
        make_tree(src, tree, node_right, mid + 1, end);
        tree[node][0] = tree[node_left][0] + tree[node_right][0];
        tree[node][1] = tree[node_left][1] + tree[node_right][1];
        tree[node][2] = tree[node_left][2] + tree[node_right][2];
        tree[node][3] = tree[node_left][3] + tree[node_right][3];
    }
}

tuple<int, int, int, int> query_tree(int (*tree)[4], int node, int start, int end, int L, int R)
{
    if (start > R || end < L)
    {
        return {0, 0, 0, 0};
    }
    if (L <= start && R >= end)
    {
        return {tree[node][0], tree[node][1], tree[node][2], tree[node][3]};
    }
    int mid = (start + end) / 2;
    int U1, D1, L1, R1, U2, D2, L2, R2;
    tie(U1, D1, L1, R1) = query_tree(tree, 2 * node + 1, start, mid, L, R);
    tie(U2, D2, L2, R2) = query_tree(tree, 2 * node + 2, mid + 1, end, L, R);
    return {U1 + U2, D1 + D2, L1 + L2, R1 + R2};
}
*/

int dat[200000][4];

signed main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < k; i++)
    {
        char dir;
        int size;
        cin >> dir >> size;
        switch (dir)
        {
        case 'U':
            dat[i][0] = size;
            break;
        case 'D':
            dat[i][1] = size;
            break;
        case 'L':
            dat[i][2] = size;
            break;
        case 'R':
            dat[i][3] = size;
            break;
        }
    }
    // make_tree(dat, tree, 0, 0, k - 1);
    for (int i = 0; i < q; i++)
    {
        int startx, starty, l, r, len = 0;
        cin >> startx >> starty >> l >> r;
        l--, r--;
        for (int j = l; j <= r; j++)
        {
            if (dat[j][0])
            {

                if (starty + dat[j][0] <= m)
                {
                    starty += dat[j][0];
                    len += dat[j][0];
                }
                else
                {
                    len += (m - starty);
                    starty = m;
                }
            }
            else
            {
                if (starty - dat[j][1] >= 0)
                {
                    starty -= dat[j][1];
                    len += dat[j][1];
                }
                else
                {
                    len += starty;
                    starty = 0;
                }
            }
            if (dat[j][3])
            {

                if (startx + dat[j][3] <= n)
                {
                    startx += dat[j][3];
                    len += dat[j][3];
                }
                else
                {
                    len += (n - startx);
                    startx = n;
                }
            }
            else
            {
                if (startx - dat[j][2] >= 0)
                {
                    startx -= dat[j][2];
                    len += dat[j][2];
                }
                else
                {
                    len += startx;
                    startx = 0;
                }
            }
        }
		cout << startx << ' ' << starty << ' ' << len << '\n';
    }
}
