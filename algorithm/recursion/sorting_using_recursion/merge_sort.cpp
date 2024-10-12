#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e, int mid) {
  int n1 = mid - s + 1;
  int n2 = e - mid;

  vector<int> leftPart(n1), rightPart(n2);

  int firstArrStart = s;
  for (int i = 0; i < n1; i++) {
    leftPart[i] = arr[firstArrStart++];
  }

  int secondArrStart = mid + 1;
  for (int i = 0; i < n2; i++) {
    rightPart[i] = arr[secondArrStart++];
  }

  // merge 2 sorted array
  int i = 0;
  int j = 0;
  int k = s;

  while (i < n1 && j < n2) {
    if (leftPart[i] < rightPart[j]) {
      arr[k++] = leftPart[i++];
    } else {
      arr[k++] = rightPart[j++];
    }
  }

  while (i < n1) {
    arr[k++] = leftPart[i++];
  }

  while (j < n2) {
    arr[k++] = rightPart[j++];
  }
}

void mergeSort(int *arr, int s, int e) {
  if (s >= e)
    return;

  int mid = s + (e - s) / 2;

  // leftPart part
  mergeSort(arr, s, mid);

  // right part
  mergeSort(arr, mid + 1, e);

  // merge
  merge(arr, s, e, mid);
}

int main() {
  int arr[5] = {2, 5, 1, 6, 9};
  int n = 5;

  mergeSort(arr, 0, n - 1);

  for (int val : arr) {
    cout << val << " ";
  }

  return 0;
}