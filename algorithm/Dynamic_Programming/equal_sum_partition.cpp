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

    if(s%2 == 0){
        int sum = s / 2;

        bool dp[n + 1][sum + 1];

        for (int i = 0; i <= n; i++){
            dp[i][0] = true;
        }

        for (int j = 1; j <= sum; j++){
            dp[0][j] = false;
        }

        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= sum; j++) {
            if(arr[i-1] <= j){
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
          }
        }

        if (dp[n][sum]) {
            cout << "Sum partition is possible";
        }else{
          cout << "Sum partition is not possible";
        }
    }else{
        cout << "Sum partition is not possible";
    }

    return 0;
}