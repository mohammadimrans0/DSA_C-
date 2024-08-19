#include<bits/stdc++.h>
using namespace std;

bool isPresent(int arr[][4], int target, int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(arr[i][j] == target){
                return true;
                break;
            }
        }
    }
    return false;
}

int main(){
    // create 2d array
    int arr[3][4];

    // taking input --> row wise input
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            cin >> arr[i][j];
        }
    }

    // taking input --> col wise input
    // for (int i = 0; i < 4; i++){
    //     for (int j = 0; j < 3; j++){
    //         cin >> arr[j][i];
    //     }
    // }

    // print 2d array
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }

    // search element on 2d array
    cout << "Enter the element to search " << endl;
    int target;
    cin >> target;

    if(isPresent(arr, target, 3,4)){
        cout << "Element Found";
    }else{
        cout << "Not Found";
    }

    return 0;
}