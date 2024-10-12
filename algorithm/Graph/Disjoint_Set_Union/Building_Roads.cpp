#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
  // constructor
  UnionFind(int n) {
    parent.resize(n + 1);
    rank.resize(n + 1, 0);

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

int main(){
    int n, e;
    cin >> n >> e;

    UnionFind unionFind(n);

    while(e--){
        int u, v;
        cin >> u >> v;

        int leaderA = unionFind.find(u);
        int leaderB = unionFind.find(v);

        if(leaderA != leaderB){
            unionFind.unionSets(u, v);
        }
    }

    vector<int> leader;
    for (int i = 1; i <= n; i++){
        leader.push_back(unionFind.find(i)); 
    }

    sort(leader.begin(), leader.end());
    leader.erase(unique(leader.begin(), leader.end()), leader.end());

    cout << leader.size() - 1 << endl;

    for (int i = 0; i < leader.size() - 1; i++)
    {
        cout << leader[i] << " " << leader[i+1] << endl;
    }

    return 0;
}