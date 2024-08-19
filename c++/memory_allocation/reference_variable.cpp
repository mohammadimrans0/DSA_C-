#include<bits/stdc++.h>
using namespace std;

void update (int &n){
    // pass value by reference
    n++;
    cout << n << endl;
}

int main(){
    int i = 4;

    // create a reference variable;
    int &j = i;

    cout << i << endl;
    cout << j << endl;

    int n = 10;
    update(n);

    return 0;
}