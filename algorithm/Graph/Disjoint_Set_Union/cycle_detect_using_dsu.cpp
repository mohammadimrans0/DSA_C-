#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
  // constructor
  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);

    for (int i = 0; i < n; ++i) {
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

    bool cycle = false;

    while(e--){
        int u, v;
        cin >> u >> v;

        if(unionFind.find(u) == unionFind.find(v)){
            cycle = true;
        }else{
          unionFind.unionSets(u, v);
        }
    }

    if(cycle){
        cout << "Cycle Found";
    }else{
        cout << "Cycle Not Found";
    }

    return 0;
}