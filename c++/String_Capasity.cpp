#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "hello world";

  cout << s.size() << endl;
  cout << s.max_size() << endl;
  cout << s.capacity() << endl;
  
  if(s.empty() == true)
      cout << "Empty" << endl;
      else
          cout << "Not Empty" << endl;

      string s1 = "hello";
      s.resize(4);
      cout << s << endl;
      return 0;
}