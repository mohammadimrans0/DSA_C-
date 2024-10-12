#include<bits/stdc++.h>
using namespace std;

void adjListToAdjMatrix(int n, vector<vector<int>>&adj){
    int mat[n][n];
    memset(mat, 0, sizeof(mat));

    for (int i = 0; i < n; i++){
        for(int child: adj[i]){
            mat[i][child] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl; 
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    vector<vector<int>>adjList(n);

    while (e--)
    {
        int u, v;
        cin >> u>> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    adjListToAdjMatrix(n, adjList);

    return 0;
}