#include<bits/stdc++.h>
using namespace std;

int main(){
    string a = "hello";
    string b = "world";
    string c = "hello";

    a += b;
    c.append(b);

    cout << a << endl;
    cout << c << endl;

    string d = "hello";
    d.push_back('A');
    cout << d << endl;
    
    d.pop_back();
    cout << d << endl;

    d.erase(1,1); // first value is from what index and second value is how much character from that that index.
    cout << d << endl;

    d.replace(1,1, "a");
    cout << d << endl;

    d.insert(2, "imran");
    cout << d << endl;

    return 0;
}