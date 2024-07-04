#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> vis(N, false);
vector<int> parentArray(N, -1);
bool ans;

void dfs(int parent) {
  vis[parent] = true;
  // cout << parent << endl;
  for (int child : adj[parent]) {
    if (vis[child] == true && child != parentArray[parent]) {
      ans = true;
    }
    if (vis[child] == false) {
      parentArray[child] = parent;
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
    adj[a].push_back(b);
    adj[b].push_back(a);
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