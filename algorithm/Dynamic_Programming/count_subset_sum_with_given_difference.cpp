#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, givenDifference;
  cin >> n >> givenDifference;

  int s = 0;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    s += arr[i];
  }

  if ((s + givenDifference) % 2 != 0) {
    cout << 0;
    return 0;
  }

  int possibleSum = (s + givenDifference) / 2;

  int dp[n + 1][possibleSum + 1];

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }

  for (int j = 1; j <= possibleSum; j++) {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= possibleSum; j++) {
      if (arr[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n][possibleSum];

  return 0;
}