#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int value;
  Node *next;

  Node(int value) {
    this->value = value;
    this->next = NULL;
  }
};

void insert_at_tail(Node *&head, Node *&tail, int val) {
  Node *newNode = new Node(val);
  if (head == NULL) {
    head = newNode;
    tail = newNode;
    return;
  }
  tail->next = newNode;
  tail = newNode;
}

void print_linked_list(Node *n) {
  // base case
  if (n == NULL)
    return;

  cout << n->value << " ";
  print_linked_list(n->next);
}

int main() {
  int value;
  Node *head = NULL;
  Node *tail = NULL;
  while (true) {
    cin >> value;
    if (value == -1)
      break;
    insert_at_tail(head, tail, value);
  }

  for (Node *i = head; i->next != NULL; i = i->next) {
    for (Node *j = i->next; j != NULL; j = j->next) {
      if (i->value > j->value) {
        swap(i->value, j->value);
      }
    }
  }

  print_linked_list(head);

  return 0;
}