#include<bits/stdc++.h>
using namespace std;

void printArray(int *ptr, int size){
    for (int i = 0; i < size;i++){
        cout << "Element " << i << ": " << *(ptr + 1) << endl;
    }
}

int getSum (int arr[], int n){
    // int " *arr " and int " arr[] " is same.
    
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
  int arr[5] = {10, 20, 30, 40, 50};
  printArray(arr, 5); // Pass the first element address of the array.

  int sum = getSum(arr, 5);
  cout << "sum is: " << sum << endl;

  return 0;
}