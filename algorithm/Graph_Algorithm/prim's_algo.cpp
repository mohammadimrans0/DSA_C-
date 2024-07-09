/*
prim's algorithem is used to find the minimum spanning tree of a graph.

MST stands for Minimum Spanning Tree. A spanning tree of a graph is a subgraph that includes all the vertices of the original graph with the minimum number of edges required to connect all the vertices without any cycles. The "minimum" in Minimum Spanning Tree refers to the sum of the weights of the edges in the tree being as small as possible.
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Min-heap priority queue to store the edges
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start the algorithm
    key[1] = 0;
    parent[1] = -1;
    pq.push({0, 1}); // {weight, node}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (!mst[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

int main() {
    // Example usage
    int n = 5; // Number of nodes
    int m = 6; // Number of edges
    vector<pair<pair<int, int>, int>> g = {
        {{1, 2}, 2},
        {{1, 3}, 3},
        {{2, 3}, 1},
        {{2, 4}, 4},
        {{3, 4}, 5},
        {{4, 5}, 6}
    };

    vector<pair<pair<int, int>, int>> result = calculatePrimsMST(n, m, g);

    for (auto edge : result) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}
