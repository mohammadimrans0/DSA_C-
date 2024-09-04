/*
Kruskal's Algorithm(graph G):
    1. Create a new empty list to store the edges of the MST.
    2. Sort all edges in non-decreasing order of their weight.
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
class Edge {
  public:
   int u, v, w;
   Edge(int u, int v, int w){
     this->u = u;
     this->v = v;
     this->w = w;
   }
};


class UnionFind {
public:
  // constructor
  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);

    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  // dsu find method
  int find(int u) {
    if (parent[u] != u) {
      parent[u] = find(parent[u]); // Path compression
    }
    return parent[u];
  }

  // dsu set-union method
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
  sort(edges.begin(), edges.end(), [](const Edge &a, Edge &b)
       { return a.w < b.w; });

  int totalCost = 0;

  // Step 2: Process edges in sorted order
  for (const auto &edge : edges) {
    if (unionFind.find(edge.u) != unionFind.find(edge.v)) {
      unionFind.unionSets(edge.u, edge.v);
      totalCost += edge.w;
      mst.push_back(edge);
    }
  }
  cout << "Total Cost: " << totalCost << endl;
  return mst; // Return the MST edges
}

int main() {
  int n, e;
  cin >> n >> e;
  vector<Edge> edges;

  while (e--)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back(Edge(u, v, w));
  }

  // Get the MST by calling the Kruskal function
  vector<Edge> mst = kruskal(edges, n);

  // Print the edges in the MST
  cout << "Edges in the MST:\n";
  for (const auto &edge : mst) {
    cout << edge.u << " - " << edge.v << " : " << edge.w << endl;
  }

  return 0;
}
