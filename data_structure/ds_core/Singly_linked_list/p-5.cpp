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

void removeDuplicates(Node *head) {
  if (!head)
    return;

  vector<int> seen;
  seen.push_back(head->value);

  Node *prev = head;
  Node *curr = head->next;

  while (curr) {
    if (find(seen.begin(), seen.end(), curr->value) != seen.end()) {
      prev->next = curr->next;
      delete curr;
      curr = prev->next;
    } else {
      seen.push_back(curr->value);
      prev = curr;
      curr = curr->next;
    }
  }
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

  removeDuplicates(head);
  print_linked_list(head);

  return 0;
}