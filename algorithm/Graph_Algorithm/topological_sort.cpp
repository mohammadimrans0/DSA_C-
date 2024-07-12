#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and store the result in the stack
void dfs(int v, const vector<vector<int>> &adj, vector<bool> &visited,
         stack<int> &Stack) {
  visited[v] = true; // Mark the current node as visited

  // Recursively visit all the adjacent vertices
  for (int i : adj[v]) {
    if (!visited[i]) {
      dfs(i, adj, visited, Stack);
    }
  }

  // Push the current node to the stack
  Stack.push(v);
}

// Function to perform topological sort
vector<int> topologicalSort(int V, const vector<vector<int>> &adj) {
  stack<int> Stack;
  vector<bool> visited(V, false);

  // Call the recursive helper function to store topological sort starting from
  // all vertices one by one
  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      dfs(i, adj, visited, Stack);
    }
  }

  // Store the result in a vector to return
  vector<int> result;
  while (!Stack.empty()) {
    result.push_back(Stack.top());
    Stack.pop();
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
  vector<int> result = topologicalSort(V, adj);

  // Print the result
  cout << "Topological Sort: ";
  for (int i : result) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
