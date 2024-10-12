#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int sum;
  cin >> sum;

  bool dp[n+1][sum+1];

  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }

  for (int j = 1; j <= sum; j++) {
    dp[0][j] = false;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if(arr[i-1] <= j){
          bool opt1 = dp[i - 1][j - arr[i - 1]];

          bool opt2 = dp[i - 1][j];

          dp[i][j] = opt1 || opt2;
      }else{
          dp[i][j] = dp[i - 1][j];
      }
    }
  }

  if (dp[n][sum]) {
    cout << "The is possible by subset" << endl;
  } else {
    cout << "Not possible" << endl;
  }

  return 0;
}