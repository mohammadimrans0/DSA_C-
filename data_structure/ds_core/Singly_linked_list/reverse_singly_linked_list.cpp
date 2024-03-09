#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node(int val) {
    this->val = val;
    this->next = NULL;
  }
};

void print_forward(Node *head) {
  Node *tmp = head;
  while (tmp != NULL) {
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
}

void reverse_singly_list(Node *&head, Node *curr) {
  if (curr->next == NULL) {
    head = curr;
    return;
  }

  reverse_singly_list(head, curr->next);
  curr->next->next = curr;
  curr->next = NULL;
}

int main() {
  Node *head = new Node(10);
  Node *a = new Node(20);
  Node *b = new Node(30);
  Node *c = new Node(40);

  head->next = a;
  a->next = b;
  b->next = c;

  reverse_singly_list(head, head);

  print_forward(head);
  
  return 0;
}