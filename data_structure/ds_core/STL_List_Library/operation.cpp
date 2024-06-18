#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> list1 = {1, 2, 6, 3, 5, 9, 3, 7};

    list1.sort();
    // list1.sort(greater<int>());  descending order

    list1.remove(9);

    list1.unique(); // remove same value and keep only unique value. but list must be sorted.

    list1.reverse();

    for (int val : list1) {
      cout << val << " ";
    }
    return 0;
}