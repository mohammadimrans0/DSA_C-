#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i]) {
        swap(arr[j], arr[i]);
      }
    }
  }

  // printing result
  for (int val : arr) {
    cout << val << " ";
  }
  cout << endl;
}

int main() {
  vector<int> arr = {6, 2, 8, 4, 10};
  selectionSort(arr, 5);

  return 0;
}