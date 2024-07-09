/**
simple tecnic:

ami amon akta node a geci jeta visited kintu oita amar parent noi. ar mane holo ai graph a cycle ace.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> vis(N, false);
vector<int> parentArray(N, -1);
bool ans;

void bfs(int s) {
  queue<int> q;
  q.push(s);
  vis[s] = true;

  while (!q.empty()) {
    int parent = q.front();
    q.pop();

    for (int child : adj[parent]) {
      if (vis[child] == true && parentArray[parent] != child) {
        ans = true;
      }

      if (vis[child] == false) {
        vis[child] = true;
        parentArray[child] = parent;
        q.push(child);
      }
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
      bfs(i);
    }
  }

  if (ans) {
    cout << "Cycle found";
  } else {
    cout << "Cycle not found";
  }

  return 0;
}