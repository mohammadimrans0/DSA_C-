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