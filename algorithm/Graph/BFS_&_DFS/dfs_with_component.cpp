#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and store the component
void dfs(int v, const vector<vector<int>> &adj, vector<bool> &visited,
         vector<int> &component) {
  visited[v] = true;
  component.push_back(v);
  for (int neighbor : adj[v]) {
    if (!visited[neighbor]) {
      dfs(neighbor, adj, visited, component);
    }
  }
}

int main() {
  int V, E;
  cin >> V >> E;

  vector<vector<int>> adj(V); // Adjacency list representation

  // Reading the edges
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> visited(V, false);
  vector<vector<int>> components;

  // Perform DFS for each vertex
  for (int i = 0; i < V; ++i) {
    if (!visited[i]) {
      vector<int> component;
      dfs(i, adj, visited, component);
      components.push_back(component);
    }
  }
  
  sort(components.begin(), components.end());

  // Output the results
  cout << components.size() << endl;
  for (const auto &component : components) {
    for (int vertex : component) {
      cout << vertex << " ";
    }
    cout << endl;
  }

  return 0;
}
