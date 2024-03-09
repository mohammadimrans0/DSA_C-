#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> stk;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        stk.push(x);
  }

  while (!stk.empty()) {
    cout << stk.top() << endl;
    stk.pop();
  }

  return 0;
}