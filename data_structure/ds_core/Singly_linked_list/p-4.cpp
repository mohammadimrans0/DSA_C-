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

void insert_at_tail(Node *&head, int value) {
  Node *newNode = new Node(value);

  if (head == NULL) {
    head = newNode;
    return;
  }

  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  // temp is now in the last node.
  temp->next = newNode;
}

void print_linked_list(Node *n) {
  // base case
  if (n == NULL)
    return;

  cout << n->value << " ";
  print_linked_list(n->next);
}

void insert_at_head(Node *&head, int v) {
  Node *newNode = new Node(v);
  newNode->next = head;
  head = newNode;
}

void delete_from_position(Node *head, int pos) {
  Node *tmp = head;
  for (int i = 0; i < pos - 1; i++) {
    tmp = tmp->next;
    if (tmp == NULL) {
      return;
    }
  }
  if (tmp->next == NULL) {
    return;
  }
  Node *deleteNode = tmp->next;
  tmp->next = tmp->next->next;
  delete deleteNode;
}

void delete_head(Node *&head) {
  Node *deleteNode = head;
  head = head->next;
  delete deleteNode;
}

int main() {
  int t;
  cin >> t;

  Node *head = NULL;
  while (t--) {

    int x, v;
    cin >> x >> v;

    if (x == 0) {
      insert_at_head(head, v);
      print_linked_list(head);
      cout << endl;
    } else if (x == 1) {
      insert_at_tail(head, v);
      print_linked_list(head);
      cout << endl;
    } else if (x == 2) {
      if (v == 0) {
        delete_head(head);
      } else {
        delete_from_position(head, v);
      }
      print_linked_list(head);
      cout <<endl;
    }
  }

  return 0;
}