#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
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
  bubbleSort(arr, 5);

  return 0;
}