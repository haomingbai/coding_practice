#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int spicy_value[100000];

/// @brief This struct is used to store the node with the shortest distance,
struct node_with_distance
{
    size_t node_index;
    double distance;
    node_with_distance(pair<int, double> &&node) : node_index(node.first), distance(node.second) {}
    node_with_distance(size_t idx, double dis) : node_index(idx), distance(dis) {}
};

bool operator<(const node_with_distance a, const node_with_distance b)
{
    return a.distance > b.distance;
}

/// @brief This to_edge indicates an edge to node destination.
struct to_edge
{
    size_t destination;
    double length;
    to_edge(size_t des, double len) : destination(des), length(len) {}
};

vector<size_t> nxt;
vector<to_edge> to;
vector<size_t> head(100000);

auto add_edge(size_t departure, size_t terminal, double length = 1) -> void
{
    nxt.emplace_back(head[departure]);
    head[departure] = to.size(); // This will be the index of the edge to be added.
    // After the two steps, nxt[head[departure]] means the edge added last time before the edge mentioned in head[departure]. At this time, head[departure] means that the edge being added should be stored in to[head[departure]] while nxt[head[departure]] store the previous head[departure].
    to.emplace_back(terminal, length);
}

int main()
{
    int n, m, q;
    for (size_t i = 0; i < n; i++)
    {
        cin >> spicy_value[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        add_edge(u, v);
        add_edge(v, u);
    }
    head.
    for (size_t i = 0; i < q; i++)
    {
        int p, a;
        cin >> p >> a;
        queue<size_t> wait;
        wait.push(p);
        size_t cnt(0);
        int curr = 101;
        while (curr >= a)
        {
            cnt++;
            for (int i = wait.back(); ; i++)
            {
                /* code */
            }
            
        }
        
    }
}