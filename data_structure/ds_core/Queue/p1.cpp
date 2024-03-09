#include <bits/stdc++.h>
using namespace std;

int main() {
  stack<int> s;
  queue<int> q;

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.push(x);
  }

  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    q.push(x);
  }

  bool same = true;

  if (s.size() != q.size()) {
    same = false;
    cout << "NO" << endl;
    return 0;
  }

  while (!s.empty() && !q.empty()) {
    if (s.top() != q.front()) {
      same = false;
      break;
    }
    s.pop();
    q.pop();
  }

  if (same) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}