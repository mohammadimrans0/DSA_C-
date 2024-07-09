/*
jdi kono node visited take (visited[node] == true]) and oi node tar dfs call o hoye gece (dfs[node] == true) tahole oi directed graph a cycle ace.

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> vis(N, false);
vector<bool> pathVisit(N, false);
bool ans;

void dfs(int node) {
  vis[node] = true;
  pathVisit[node] = true;

  for (int child : adj[node]) {
    if (pathVisit[child]) {
      ans = true;
    }

    if (!vis[child]) {
      dfs(child);
    }
  }

  pathVisit[node] = false;
}

int main() {
  int n, e;
  cin >> n >> e;
  while (e--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  ans = false;

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  if (ans) {
    cout << "Cycle detected";
  } else {
    cout << "Cycle not detected";
  }

  return 0;
}