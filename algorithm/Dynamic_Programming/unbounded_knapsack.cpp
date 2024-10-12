#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int unbounded_knapsack(int n, int w, int *value, int *weight){
    if(n == 0 || w == 0){
        return 0;
    }

    if(dp[n][w] != -1){
        return dp[n][w];
    }

    if(weight[n-1] <= w){
        int opt1 = value[n - 1] + unbounded_knapsack(n, w - weight[n - 1], value, weight);

        int opt2 = unbounded_knapsack(n - 1, w, value, weight);

        return dp[n][w] = max(opt1, opt2);
    }else{
      return dp[n][w] = unbounded_knapsack(n - 1, w, value, weight);
    }
}

int main(){
  int n, w;
  cin >> n >> w;

  int value[n], weight[n];

  for (int i = 0; i < n; i++) {
    cin >> value[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      dp[i][j] = -1;
    }
  }

  cout << unbounded_knapsack(n, w, value, weight) << endl;

  return 0;
}