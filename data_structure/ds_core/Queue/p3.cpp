#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    int n = s.size();

    stack<char> stk;

    for (int i = 0; i < n; i++) {
      if (stk.empty()) {
        stk.push(s[i]);
      } else if (s[i] == '1' && stk.top() == '0') {
        stk.pop();
      } else if (s[i] == '0' && stk.top() == '1') {
        stk.pop();
      } else {
        stk.push(s[i]);
      }
    }

    if (stk.empty()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}