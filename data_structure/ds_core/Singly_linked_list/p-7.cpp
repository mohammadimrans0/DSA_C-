// https://www.hackerrank.com/contests/mid-term-exam-a-basic-data-structures-a-batch-04/challenges/browser-history-1

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  list<string> address;

  while (cin >> s && s != "end") {
    address.push_back(s);
  }

  int q;
  cin >> q;

  auto current = address.begin();

  while (q--) {
    string cmd;
    cin >> cmd;

    if (cmd == "visit") {
      string address_name;
      cin >> address_name;

      auto it = find(address.begin(), address.end(), address_name);

      if (it == address.end()) {
        cout << "Not Available" << endl;
      } else {
        if (*it != *current) {
          current = it;
        }
        cout << *current << endl;
      }

    } else if (cmd == "next") {
      if (next(current) != address.end()) {
        ++current;
        cout << *current << endl;
      } else {
        cout << "Not Available" << endl;
      }

    } else if (cmd == "prev") {
      if (current != address.begin()) {
        --current;
        cout << *current << endl;
      } else {
        cout << "Not Available" << endl;
      }
    }
  }

  return 0;
}