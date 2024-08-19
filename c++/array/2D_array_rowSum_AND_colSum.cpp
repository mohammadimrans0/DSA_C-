#include <bits/stdc++.h>
using namespace std;

void printRowSum(int arr[][4], int row, int col) {
  cout << "Printing Row Sum :" << endl;
  for (int i = 0; i < row; i++) {
    int sum = 0;
    for (int j = 0; j < col; j++) {
      sum += arr[i][j];
    }
    cout << sum << " ";
  }
  cout << endl;
}

void printColSum(int arr[3][4], int row, int col) {
  cout << "Printing Col Sum :" << endl;
  for (int i = 0; i < col; i++) {
    int sum = 0;
    for (int j = 0; j < row; j++) {
      sum += arr[j][i];
    }
    cout << sum << " ";
  }
  cout << endl;
}

int main() {
  int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  printRowSum(arr, 3, 4);

  printColSum(arr, 3, 4);

  return 0;
}