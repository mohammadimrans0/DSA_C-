#include<bits/stdc++.h>
using namespace std;

int main(){
    int num = 5;

    cout << num << endl;

    //address of Operator - &
    cout << "address of num is " << &num << endl;

    //initialize pointer
    int *ptr = &num;

    cout << "value is: " << *ptr << endl;

    // copying pointer
    int *q = ptr;

    cout << "ptr is: " << *ptr << " and "
         << "q is: " << *q << endl;

    return 0;
}