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

void print_forward(Node *head) {
  Node *tmp = head;
  while (tmp != nullptr) {
    cout << tmp->value << " ";
    tmp = tmp->next;
  }
  cout << endl;
}

void print_backward(Node *tail) {
  Node *tmp = tail;
  while (tmp != nullptr) {
    cout << tmp->value << " ";
    tmp = tmp->prev;
  }
  cout << endl;
}

void insert_at_position(Node *head, int pos, int val) {
  Node *newNode = new Node(val);
  Node *tmp = head;

  for (int i = 1; i < pos; i++) {
    tmp = tmp->next;
  }

  newNode->next = tmp->next;
  tmp->next = newNode;
  newNode->next->prev = newNode;
  newNode->prev = tmp;
}

int size(Node *head) {
  Node *tmp = head;
  int cnt = 0;
  while (tmp != nullptr) {
    cnt++;
    tmp = tmp->next;
  }
  return cnt;
}

void insert_head(Node *&head, Node *&tail, int val) {
  Node *newNode = new Node(val);

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
    return;
  }
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void insert_tail(Node *&head, Node *&tail, int val) {
  Node *newNode = new Node(val);
  if(tail == nullptr){
      head = newNode;
      tail = newNode;
      return;
  }

  tail->next = newNode;
  newNode->prev = tail;
  tail = tail->next;
}

int main() {

//   Node *head = nullptr;
//   Node *tail = nullptr;

  Node *head = new Node(10);
  Node *a = new Node(20);
  Node *b = new Node(30);
  Node *c = new Node(40);
  Node *tail = c;

  // connection
  head->next = a;
  a->prev = head;
  a->next = b;
  b->prev = a;
  b->next = c;
  c->prev = b;

  int pos, val;
  cin >> pos >> val;

  if (pos == 0) {
    insert_head(head, tail, val);
  } else if (pos == size(head)) {
    insert_tail(head, tail, val);
  } else if (pos > size(head)) {
    cout << "Invalid" << endl;
  } else {
    insert_at_position(head, pos, val);
  }

  print_forward(head);
  print_backward(tail);

  return 0;
}