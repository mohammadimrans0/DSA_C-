#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++) {
      adjList[i].push_back(i);
    }

    for (int i = 0; i < e; i++) {
      int u, v;
      cin >> u >> v;

      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
      cout << "vertex " << i << ":";
      for (int j = 0; j < adjList[i].size(); j++) {
        cout << " " << adjList[i][j];
      }
      cout << endl;
    }

    return 0;
}