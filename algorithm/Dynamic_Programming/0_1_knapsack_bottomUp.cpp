#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int value[n], weight[n];

  for (int i = 0; i < n; i++) {
    cin >> value[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  int w;
  cin >> w;

  int dp[n + 1][w + 1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      if (i == 0 || j == 0) {
          dp[i][j] = 0;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= w; j++) {
      if (weight[i-1] <= j) {
          int opt1 = dp[i - 1][j - weight[i - 1]] + value[i - 1];

          int opt2 = dp[i - 1][j];

          dp[i][j] = max(opt1, opt2);
      }else{
          dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n][w] << endl;

  return 0;
}

// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U