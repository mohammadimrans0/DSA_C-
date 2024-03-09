#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int value;
  Node *next;
  Node *prev;

  Node(int value) {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class myStack {
public:
  Node *head = nullptr;
  Node *tail = nullptr;

  int sz = 0;

  void push(int val) {
    sz++;

    Node *newNode = new Node(val);
    if (head == nullptr) {
      head = tail = newNode;
      return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = tail->next;
  }

  void pop() {
    sz--;

    Node *deleteNode = tail;
    tail = tail->prev;
    if (tail == nullptr)
      head = nullptr;
    else
      tail->next = nullptr;
    delete deleteNode;
  }

  int top() { return tail->value; }

  int size() { return sz; }

  bool empty() {
    if (sz == 0)
      return true;
    else
      return false;
  }
};

int main() {

  myStack stk;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    stk.push(x);
  }

  while (!stk.empty()) {
    cout << stk.top() << endl;
    stk.pop();
  }

  return 0;
}