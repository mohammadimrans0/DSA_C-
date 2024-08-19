#include<bits/stdc++.h>
using namespace std;

int main(){
  int arr[5] = {10, 20, 30, 40, 50};
  int *ptr = arr; // ptr now points to the first element of arr

  cout << *ptr << endl;
  cout << *(ptr + 1) << endl;
  cout << *(ptr + 2) << endl;

  // When you increment a pointer, it moves to the next element of the array (not the next byte).

  ptr++;
  cout << *ptr << endl; // it will print arr[1];

  return 0;
}

/*
formula :

=> arr[i] = *(arr + i);
=> i[arr] = *(i + arr);

 */