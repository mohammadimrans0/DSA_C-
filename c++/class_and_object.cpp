#include <bits/stdc++.h>
using namespace std;

class Student {
public:
  char name[100];
  int roll;
  double cgpa;
};

int main() {
  Student a,b;

  // a.roll = 29;
  // a.cgpa = 3.95;

  // char temp[100] = "rakib";
  // strcpy(a.name, temp);

  // taking input
  cin.getline(a.name, 100);
  cin >> a.roll >> a.cgpa;

  getchar(); // it use to remove enter

  cin.getline(b.name, 100);
  cin >> b.roll >> b.cgpa;

  cout << a.name << " " << a.roll << " " << a.cgpa << endl;

  cout << b.name << " " << b.roll << " " << b.cgpa << endl;

  return 0;
}