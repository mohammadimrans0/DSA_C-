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

void reverse_doubly_linked_list(Node *head) {
  Node *i = head;
  Node *j = head;

  while (j->next != nullptr) {
    j = j->next;
  }

  while (i != j && i->prev != j) {
    swap(i->value, j->value);
    i = i->next;
    j = j->prev;
  }
}

int main() {

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

  reverse_doubly_linked_list(head);

  print_forward(head);

  return 0;
}