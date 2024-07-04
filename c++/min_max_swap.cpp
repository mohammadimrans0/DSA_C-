#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int minimum = min({a, b, c, d});
    int maximum = max({a, b, c, d});

    cout << minimum << endl << maximum << endl;

    int x, y;
    cin >> x >> y;
    swap(x, y);
    cout << x << " " << y;

    return 0;
}