#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
  int u, v, c;
  Edge(int u, int v, int c) {
    this->u = u;
    this->v = v;
    this->c = c;
  }
};

const int N = 1e5 + 5;
vector<int> dis(N, INT_MAX);

int main() {
  int n, e;
  cin >> n >> e;
  vector<Edge> EdgeList;
  while (e--) {
    int u, v, c;
    cin >> u >> v >> c;
    EdgeList.push_back(Edge(u, v, c));
  }

  dis[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (Edge ed : EdgeList) {
      int u, v, c;
      u = ed.u;
      v = ed.v;
      c = ed.c;

      if (dis[u] < INT_MAX && dis[u] + c < dis[v]) {
        dis[v] = dis[u] + c;
      }
    }
  }

  // Check for negative weight cycles
  bool hasNegativeCycle = false;
  for (Edge ed : EdgeList) {
    int u = ed.u;
    int v = ed.v;
    int c = ed.c;

    if (dis[u] < INT_MAX && dis[u] + c < dis[v]) {
      hasNegativeCycle = true;
      break;
    }
  }

  if (hasNegativeCycle) {
    cout << "Graph contains a negative weight cycle" << endl;
  } else {
      for (int i = 0; i < n;i++){
        cout << "Vertex " << i << ": " << dis[i] << endl;
      }
  }

  return 0;
}