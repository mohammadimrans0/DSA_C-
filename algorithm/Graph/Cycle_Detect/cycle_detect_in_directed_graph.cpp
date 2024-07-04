#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> vis(N, false);
vector<bool> pathVisit(N, false);
bool ans;

void dfs(int parent) {
  vis[parent] = true;
  pathVisit[parent] = true;

  for (int child : adj[parent]) {
    if (pathVisit[child]) {
      ans = true;
    }

    if (vis[child] == false) {
      dfs(child);
    }
  }

  pathVisit[parent] = false;
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