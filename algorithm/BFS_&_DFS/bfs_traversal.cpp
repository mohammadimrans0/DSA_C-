#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
vector<bool> visited(1005, false);

void bfs(int src) {
  queue<int> q;
  q.push(src);
  visited[src] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    cout << u << endl;

    for (int v : v[u]) {
      if (visited[v] == false) {
        q.push(v);
        visited[v] = true;
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

    v[a].push_back(b);
    v[b].push_back(a);
  }

  int src;
  cin >> src;

  bfs(src);

  return 0;
}