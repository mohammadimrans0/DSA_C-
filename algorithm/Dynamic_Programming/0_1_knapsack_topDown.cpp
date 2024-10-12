#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int knapsack(int n, int *value, int *weight, int w) {
  if (n == 0 || w == 0) {
    return 0;
  }

  if (dp[n][w] != -1) {
    return dp[n][w];
  }

  if (weight[n] <= w) {
    // two option : either take it or not

    int opt1 = knapsack(n - 1, value, weight, w - weight[n-1]) + value[n-1];

    int opt2 = knapsack(n - 1, value, weight, w);

    return dp[n][w] = max(opt1, opt2);
  } else {
    // one option: can't take it
    return dp[n][w] = knapsack(n - 1, value, weight, w);
  }
}

int main() {
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

  cout << knapsack(n, value, weight, w) << endl;

  return 0;
}