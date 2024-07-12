// DAG: Directed Acyclic Graph

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
  unordered_map<int, list<pair<int, int>>> adj;

  void addEdge(int u, int v, int wt) { adj[u].push_back({v, wt}); }

  void printAdj() {
    for (auto i : adj) {
      cout << i.first << "-> ";
      for (auto j : i.second) {
        cout << "(" << j.first << ", " << j.second << "),";
      }
      cout << endl;
    }
  }

  void dfs(int node, unordered_map<int, bool> &vis, stack<int> &topo) {
    vis[node] = true;
    for (auto neighbour : adj[node]) {
      if (!vis[neighbour.first]) {
        dfs(neighbour.first, vis, topo);
      }
    }
    topo.push(node);
  }
};

int main() {
  Graph g;

  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 3);
  g.addEdge(1, 3, 6);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 5, 2);
  g.addEdge(3, 4, -1);
  g.addEdge(4, 5, -2);

  g.printAdj();

  int n = 6;
  // topological sort
  unordered_map<int, bool> visited;
  stack<int> s;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      g.dfs(i, visited, s);
    }
  }

  return 0;
}