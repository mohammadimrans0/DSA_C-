#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> mp;

    mp["sakib al hasan"] = 75;
    mp["tamim iqbal"] = 100;
    mp["muspiq ur rahim"] = 60;

    for (auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    cout << mp["tamim iqbal"] << endl;

    if(mp.count("muspiq ur rahim"))
        cout << "ace" << endl;
        else
        cout << "nai" << endl;
    
    return 0;
}