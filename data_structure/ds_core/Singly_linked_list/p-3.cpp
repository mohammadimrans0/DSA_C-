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

int main() {
  int value;

  // first linked list
  Node *head1 = NULL;
  Node *tail1 = NULL;
  while (true) {
    cin >> value;
    if (value == -1)
      break;
    insert_at_tail(head1, tail1, value);
  }

  // second linked list
  Node *head2 = NULL;
  Node *tail2 = NULL;
  while (true) {
    cin >> value;
    if (value == -1)
      break;
    insert_at_tail(head2, tail2, value);
  }

  bool same = true;

  while (head1 != NULL && head2 != NULL) {
    if (head1->value != head2->value) {
      same = false;
      break;
    }
    head1 = head1->next;
    head2 = head2->next;
  }

  if (same && head1 == NULL && head2 == NULL) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}