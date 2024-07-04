#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "mohammad imran";

    cout << *s.begin() << endl;
    cout << *(s.end()-1) << endl;

    string q = "iterator";
    // string::iterator it;

    for (auto it = q.begin(); it < q.end();it++){
        cout << *it << endl;
    }

    return 0;
}