#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &discovery,
         vector<int> &low, vector<vector<int>> &result,
         unordered_map<int, list<int>> &adj, vector<bool> &vis) {
  vis[node] = true;
  discovery[node] = low[node] = timer++;

  for (auto nbr : adj[node]) {
    if (nbr == parent)
      continue;

    if (!vis[nbr]) {
      dfs(nbr, node, timer, discovery, low, result, adj, vis);
      low[node] = min(low[node], low[nbr]);

      // Check if the edge is a bridge
      if (low[nbr] > discovery[node]) {
        result.push_back({node, nbr});
      }
    } else {
      // Update low value for back edge
      low[node] = min(low[node], discovery[nbr]);
    }
  }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
  // Create adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int timer = 0;
  vector<int> discovery(v, -1);
  vector<int> low(v, -1);
  vector<bool> vis(v, false);
  vector<vector<int>> result;

  // Perform DFS for each component
  for (int i = 0; i < v; i++) {
    if (!vis[i]) {
      dfs(i, -1, timer, discovery, low, result, adj, vis);
    }
  }

  return result;
}

int main() {
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3},
                               {3, 4}, {4, 5}, {4, 6}, {5, 6}};
  int v = 7; // Number of vertices
  int e = 8; // Number of edges

  vector<vector<int>> bridges = findBridges(edges, v, e);

  // Print the bridges
  cout << "Bridges in the graph are:" << endl;
  for (auto bridge : bridges) {
    cout << bridge[0] << " - " << bridge[1] << endl;
  }

  return 0;
}
