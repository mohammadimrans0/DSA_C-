#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
  // constructor
  UnionFind(int n) {
    parent.resize(n+1);
    rank.resize(n+1, 0);

    for (int i = 1; i <= n; i++) {
      parent[i] = i;
    }
  }

  // dsu find method
  int find(int u) {
    if (parent[u] != u) {
      parent[u] = find(parent[u]); // Path compression
    }
    return parent[u];
  }

  // dsu set-union method
  void unionSets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
      if (rank[root_u] > rank[root_v]) {
        parent[root_v] = root_u;
      } else if (rank[root_u] < rank[root_v]) {
        parent[root_u] = root_v;
      } else {
        parent[root_v] = root_u;
        rank[root_u]++;
      }
    }
  }

private:
  vector<int> parent, rank;
};

int main() {
  int n;
  cin >> n;

  UnionFind unionFind(n);

  vector<pair<int, int>> deleted_roads;
  vector<pair<int, int>> new_roads;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    int leader_u = unionFind.find(u);
    int leader_v = unionFind.find(v);

    if (leader_u != leader_v) {
      unionFind.unionSets(u, v);
    } else {
      deleted_roads.push_back({u, v});
    }
  }

  cout << deleted_roads.size() << endl;

  for (int i = 2; i <= n; i++) {
    int leaderA = unionFind.find(1);
    int leaderB = unionFind.find(i);

    if (leaderA != leaderB) {
      unionFind.unionSets(1, i);
      new_roads.push_back({1, i});
    }
  }

  for (int i = 0; i < deleted_roads.size(); i++) {
    cout << deleted_roads[i].first << " " << deleted_roads[i].second << " "
         << new_roads[i].first << " " << new_roads[i].second << endl;
  }

  return 0;
}