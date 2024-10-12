#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int s = 0;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        s += arr[i];
    }

    bool dp[n + 1][s + 1];

    for (int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }

    for (int j = 1; j <= s; j++) {
      dp[0][j] = false;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= s; j++) {
        if (arr[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    vector<int> subsetSum;

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= s; j++) {
          if(dp[i][j] == 1){
              subsetSum.push_back(j);
          }
      }
    }

    int ans = INT_MAX;
    for(int val: subsetSum){
        int s1 = val;
        int s2 = s - s1;

        ans = min(ans, abs(s1 - s2));
    }

    cout << ans;

    return 0;
}