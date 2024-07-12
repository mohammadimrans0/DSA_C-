// kahn's algorithm do topological sort using bfs.

#include<bits/stdc++.h>
using namespace std;

// Function to perform topological sort using Kahn's algorithm
vector<int> topologicalSort(int V, const vector<vector<int>> &adj) {
  vector<int> inDegree(V, 0);
  vector<int> result;

  // Calculate in-degrees of all vertices
  for (int i = 0; i < V; i++) {
    for (int j : adj[i]) {
      inDegree[j]++;
    }
  }

  // Initialize the queue with vertices having in-degree 0
  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (inDegree[i] == 0) {
      q.push(i);
    }
  }

  // Process the vertices
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    result.push_back(v);

    // Decrease the in-degree of adjacent vertices
    for (int u : adj[v]) {
      inDegree[u]--;
      if (inDegree[u] == 0) {
        q.push(u);
      }
    }
  }

  // Check if there was a cycle
  if (result.size() != V) {
    throw runtime_error("The graph contains a cycle and therefore does not "
                        "have a topological ordering.");
  }

  return result;
}

int main() {
  int V = 6; // Number of vertices
  vector<vector<int>> adj(V);

  // Example graph
  adj[5].push_back(2);
  adj[5].push_back(0);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

  // Perform topological sort
  try {
    vector<int> result = topologicalSort(V, adj);

    // Print the result
    cout << "Topological Sort: ";
    for (int i : result) {
      cout << i << " ";
    }
    cout << endl;
  } catch (const runtime_error &e) {
    cout << e.what() << endl;
  }

  return 0;
}
