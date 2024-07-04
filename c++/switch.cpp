#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 3;
    switch (x)
    {
    case 1:
        cout << "one" << endl;
        break;
    case 2:
        cout << "two" << endl;
        break;
    case 3:
        cout << "three" << endl;
        break;
    case 4:
        cout << "four" << endl;
        break;
    case 5:
        cout << "five" << endl;
        break;
    
    default:
        cout << "kicu nai";
        break;
    }

    int y;
    cin >> y;
    switch (y % 2)
    {
    case 0:
        cout << "Even" << endl;
        break;
    case 1:
        cout << "Odd" << endl;
        break;
    
    default:
        break;
    }

    char c;
    cin >> c;
    switch (c)
    {
    case 'a':
        cout << "Vowel";
        break;
    case 'e':
        cout << "Vowel";
        break;
    case 'i':
        cout << "Vowel";
        break;
    case 'o':
        cout << "Vowel";
        break;
    case 'u':
        cout << "Vowel";
        break;
    
    default:
        cout << "Consonant";
        break;
    }

    return 0;
}