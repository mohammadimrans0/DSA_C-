/*
Kruskal Algorithm(graph G):
    1. Create a new empty list to store the edges of the MST.
    2. Sort all edges of G in non-decreasing order of their weight.
    3. Create a Union-Find data structure to keep track of components.
    4. For each edge (u, v) in the sorted list:
        a. If Find(u) ≠ Find(v):
            i. Add edge (u, v) to the MST.
            ii. Union(u, v)
    5. Return the list of edges in the MST.

 */

#include <bits/stdc++.h>
using namespace std;

// Define the edge structure
struct Edge {
  int u, v, weight;
  bool operator<(const Edge &other) const { return weight < other.weight; }
};

// Union-Find data structure
class UnionFind {
public:
  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int find(int u) {
    if (parent[u] != u) {
      parent[u] = find(parent[u]); // Path compression
    }
    return parent[u];
  }

  void unionSets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
      if (rank[root_u] > rank[root_v]) {
        parent[root_v] = root_u;
      } else if (rank[root_u] < rank[root_v]) {
        parent[root_u] = root_v;
      } else {
        parent[root_v] = root_u;
        rank[root_u]++;
      }
    }
  }

private:
  vector<int> parent, rank;
};

// Kruskal's algorithm
vector<Edge> kruskal(vector<Edge> &edges, int numVertices) {
  vector<Edge> mst;
  UnionFind unionFind(numVertices);

  // Step 1: Sort edges by weight
  sort(edges.begin(), edges.end());

  // Step 2: Process edges in sorted order
  for (const auto &edge : edges) {
    if (unionFind.find(edge.u) != unionFind.find(edge.v)) {
      unionFind.unionSets(edge.u, edge.v);
      mst.push_back(edge);
    }
  }
  return mst; // Return the MST edges
}

int main() {
  vector<Edge> edges = {{0, 1, 1}, {1, 2, 2}, {0, 2, 4}, {0, 3, 3}, {2, 3, 5}};
  int numVertices = 4;

  // Get the MST by calling the Kruskal function
  vector<Edge> mst = kruskal(edges, numVertices);

  // Print the edges in the MST
  cout << "Edges in the MST:\n";
  for (const auto &edge : mst) {
    cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
  }

  return 0;
}
