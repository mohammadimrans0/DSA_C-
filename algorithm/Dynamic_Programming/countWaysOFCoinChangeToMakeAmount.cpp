#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int w[n];
    for (int i = 0; i < n; i++){
        cin >> w[i];
    }

    int s;
    cin >> s;

    int dp[n + 1][s + 1];

    for (int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    for (int j = 1; j <= s; j++){
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= s; j++) {
        if(w[i-1] <= j){
            dp[i][j] = dp[i][j - w[i - 1]] + dp[i - 1][j];
        }else{
            dp[i][j] = dp[i - 1][j];
        }
      }
    }

    cout << dp[n][s] << endl;

    return 0;
}