#include <bits/stdc++.h>
using namespace std;

int main() {
  list<int> myList;

  int value;
  while (true) {
    cin >> value;
    if (value == -1)
      break;
    myList.push_back(value);
  }

  set<int> newList;

  auto it = myList.begin();
  while (it != myList.end()) {
    if (newList.find(*it) != newList.end()) {
      // we got a duplicate value
      it = myList.erase(it);
    } else {
      newList.insert(*it);
      ++it;
    }
  }

  for (int x : newList) {
    cout << x << " ";
  }

  return 0;
}