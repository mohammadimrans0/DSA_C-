#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[100];
    int a;
    cin >> a;
    getchar(); // If we take any input before fgets or getline function; we use this to remove the last enter. Because, the 'enter' considered as a character.

    // cin >> s;
    // fgets(s, 100, stdin);
    cin.getline(s, 100);
    cout << a << endl;

    cout << s << endl;

    return 0;
}