#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> list1;
    list<int> list2(10, 5);
    list<int> list3 = {1, 2, 3, 4, 5};
    list<int> list4(list3);

    cout << list4.front() << endl;
    cout << list4.back() << endl;
    cout << *next(list4.begin(), 2) << endl;

    vector<int> a = {10, 20, 30, 40, 50};
    list<int> list5(a.begin(), a.end());

    // for (auto it = list5.begin(); it != list5.end(); it++){
    //     cout << *it << " ";
    // }

    for(int val:list5){
        cout << val << " ";
    }
        return 0;
}