#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int w[n];
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  int s;
  cin >> s;

  int dp[n + 1][s + 1];

  // if the sum is 0, 0 coins are needed
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }

// if no coins are available and sum is positive, set to impossible
  for (int j = 1; j <= s; j++) {
    dp[0][j] = s + 1; // set a value larger that the possible coin count
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= s; j++) {
      if (w[i - 1] <= j) {
        dp[i][j] = min(dp[i][j - w[i - 1]] + 1, dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  if (dp[n][s] > s) {
    cout << -1 << endl; // If dp[n][s] is greater than s, no solution exists
  } else {
    cout << dp[n][s] << endl;
  }

  return 0;
}