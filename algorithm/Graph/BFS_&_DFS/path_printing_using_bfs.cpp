#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<vector<int>> adjList(N);
vector<bool> vis(N, false);
vector<int> dis(N, -1);
vector<int> par(N, -1);

void bfs(int s) {
  queue<int> q;
  q.push(s);
  vis[s] = true;
  dis[s] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int child : adjList[node]) {
      if (!vis[child]) {
        vis[child] = true;
        q.push(child);
        dis[child] = dis[node] + 1;
        par[child] = node;
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

    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }

  int src, des;
  cin >> src >> des;

  bfs(src);

  int x = des;
  vector<int> path;
  while (x != -1)
  {
      path.push_back(x);
      x = par[x];
  }

  reverse(path.begin(), path.end());

  for(int val:path){
      cout << val << " ";
  }

  return 0;
}