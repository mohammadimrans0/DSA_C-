#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int, int> p;
    pair<string, int> q;

    p = make_pair(10, 20);
    q = make_pair("rahat", 50);

    cout << p.first << " " << p.second << endl;
    cout << q.first << " " << q.second << endl;

    return 0;
}