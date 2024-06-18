#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> v[N];
vector<bool> visited(N, false);

void dfs(int src) {
  cout << src << endl;
  visited[src] = true;

  for (int child : v[src]) {
    if (visited[child] == false) {
      dfs(child);
    }
  }
}

int main() {
  int n, e;
  cin >> n >> e;
  while (e--) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  dfs(0);

  return 0;
}

// alternative
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
      sort(component.begin(), component.end());
      components.push_back(component);
    }
  }

  // Sort components based on the first element of each component
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
