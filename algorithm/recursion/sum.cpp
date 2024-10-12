#include<bits/stdc++.h>
using namespace std;

int getSum(int *arr, int size){
    if(size == 0)
        return 0;
    if(size == 1)
        return arr[0];

    int sum = arr[0] + getSum(arr+1, size-1);

    return sum;
}

int main(){
    int arr[5] = {2, 3, 4, 6, 3};
    int size = 5;

    int sum = getSum(arr, size);
    cout << sum;

    return 0;
}