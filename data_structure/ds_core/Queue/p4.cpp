#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;

  queue<string> q;

  while (t--)
  {
      int a;
      string s;
      cin >> a;
      cin.ignore();
      
      if(a == 0){
        getline(cin, s);
        q.push(s);
      }else
      {
          if(!q.empty()){
              cout << q.front() << endl;
              q.pop();
          }else{
              cout << "Invalid" << endl;
          }
      }     
  }

  while(!q.empty()){
      cout << q.front() << endl;
      q.pop();
  }
  
  return 0;
}