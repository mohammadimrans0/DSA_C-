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

class myQueue {
public:
  Node *head = NULL;
  Node *tail = NULL;
  int sz = 0;
  void push(int val) {
    sz++;
    Node *newNode = new Node(val);
    if (head == NULL) {
      head = newNode;
      tail = newNode;
      return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
  }

  void pop() {
    sz--;
    Node *deleteNode = head;
    head = head->next;
    if (head == NULL) {
      tail = NULL;
      delete deleteNode;
      return;
    }
    head->prev = NULL;
    delete deleteNode;
  }

  int front() { return head->value; }

  int size() { return sz; }

  bool empty() {
    if (sz == 0)
      return true;
    else
      return false;
  }
};

int main() {
  myStack s;
  myQueue q;

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.push(x);
  }

  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    q.push(x);
  }

  bool same = true;

  if (s.size() != q.size()) {
    same = false;
    cout << "NO" << endl;
    return 0;
  }

  while (!s.empty() && !q.empty()) {
    if (s.top() != q.front()) {
      same = false;
      break;
    }
    s.pop();
    q.pop();
  }

  if (same) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}