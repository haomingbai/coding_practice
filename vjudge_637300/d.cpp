/*************************************************************************
        > File Name: d.cpp
        > Author: Haoming Bai
        > Mail: haomingbai@hotmail.com
        > Created Time: 2024年07月02日 星期二 19时25分41秒
 ************************************************************************/

#include <ios>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

inline void build_tree(long long *arr, long long *tree, long long len, long long node, long long start, long long end);
inline void update_tree(long long *tree, long long idx, long long value, long long start, long long end, long long node);
inline long long query_tree(long long *tree, long long node, long long start, long long end, long long L, long long R);
vector<list<long long>> sto;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long T;
    cin >> T;
    sto.resize(T);
    for (long long i = 0, *arr, *tree, N; i < T; i++)
    {
        cin >> N;
        arr = new long long[N];
        tree = new long long[4 * N];
        for (long long j = 0; j < N; j++)
        {
            cin >> arr[j];
        }
        build_tree(arr, tree, N, 0, 0, N - 1);
        char command[20];
        do
        {
            long long a, b;
            cin >> command;
            if (command[0] != 'E')
            {
                cin >> a >> b;
            }
            if (command[0] == 'A')
            {
                update_tree(tree, a - 1, b, 0, N - 1, 0);
            }
            else if (command[0] == 'S')
            {
                update_tree(tree, a - 1, -b, 0, N - 1, 0);
            }
            else if (command[0] == 'Q')
            {
                sto.at(i).push_back(query_tree(tree, 0, 0, N - 1, a - 1, b - 1));
            }
        } while (command[0] != 'E');
        delete[] tree;
        delete[] arr;
    }
    for (long long i = 0, *arr, *tree, N; i < T; i++)
    {
        cout << "Case " << i + 1 << ":\n";
        for (auto it : sto[i])
        {
            cout << it << '\n';
        }
    }
}

inline void build_tree(long long *arr, long long *tree, long long len, long long node, long long start, long long end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        long long mid = (start + end) / 2, node_former = 2 * node + 1, node_latter = 2 * node + 2;
        build_tree(arr, tree, len, node_former, start, mid);
        build_tree(arr, tree, len, node_latter, mid + 1, end);
        tree[node] = tree[node_former] + tree[node_latter];
    }
}

inline void update_tree(long long *tree, long long idx, long long value, long long start, long long end, long long node)
// Value positive -> add, negative -> sub
{
    if (start == end)
    {
        tree[node] += value;
    }
    else
    {
        long long mid = (start + end) / 2;
        if (idx > mid)
        {
            update_tree(tree, idx, value, mid + 1, end, 2 * node + 2);
        }
        else
        {
            update_tree(tree, idx, value, start, mid, 2 * node + 1);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

inline long long query_tree(long long *tree, long long node, long long start, long long end, long long L, long long R)
{
    if (start > R || end < L)
    {
        return 0;
    }
    if (start >= L && end <= R)
    {
        return tree[node];
    }
    long long res = 0;
    long long mid = (start + end) / 2;
    res += query_tree(tree, 2 * node + 1, start, mid, L, R);
    res += query_tree(tree, 2 * node + 2, mid + 1, end, L, R);
    return res;
}
