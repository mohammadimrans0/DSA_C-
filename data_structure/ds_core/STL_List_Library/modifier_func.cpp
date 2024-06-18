#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> list1 = {10, 20, 30};
    list<int> list2;
    list2 = list1;

    list2.push_back(200);
    list2.push_front(100);

    list2.pop_back();
    list2.pop_front();

    list2.insert(next(list2.begin(), 2), 100);
    list2.insert(next(list2.begin(), 4),{200, 300});
    list2.insert(next(list2.begin(), 6), list1.begin(), list1.end());

    list2.erase(next(list2.begin(), 2), next(list2.begin(), 5));

    replace(list2.begin(), list2.end(), 300, 30);

    for(int val:list2){
        cout << val << " ";
    }

    cout << endl;

    auto it = find(list2.begin(), list2.end(), 10);

    if(it == list2.end())
        {cout << "Nof Found";}
        else
           { cout << "Found";}

    return 0;
}