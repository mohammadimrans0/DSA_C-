#include <bits/stdc++.h>
using namespace std;

class graph {
public:
  unordered_map<int, list<int>> adj;

  void addEdge(int u, int v, bool direction) {
    // direction = 0 -> mean undirected graph
    // direction = 1 -> mean directed graph

    // create an edge from u to v
    adj[u].push_back(v);
    if (!direction) {
      adj[v].push_back(u);
    }
  }

  void printAdjList() {
    for (auto i : adj) {
      cout << i.first << "-> ";
      for (auto j : i.second) {
        cout << j << ", ";
      }
      cout << endl;
    }
  }
};

int main() {
  int n, m; // n equal to nodes and m equal to edges;
  cin >> n >> m;

  graph g;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    // created an undirected graph
    g.addEdge(u, v, 0);
  }

  // printing graph
  g.printAdjList();
  
  return 0;
}
