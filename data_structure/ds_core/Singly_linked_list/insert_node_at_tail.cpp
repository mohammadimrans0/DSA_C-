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

void print_linked_list(Node *head) {
  cout << "your linked list: " ;
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {

  Node *head = NULL;
  Node *tail = NULL;
  while (true) {
    cout << "option 1: Insert at Tail" << endl;
    cout << "option 2: Print linked list" << endl;
    cout << "option 3: Terminate" << endl;
    int opt;
    cin >> opt;

    if (opt == 1) {
      cout << "Please enter value: ";
      int value;
      cin >> value;
      insert_at_tail(head, tail, value);
    } else if (opt == 2) {
      print_linked_list(head);
    } else if (opt == 3) {
      break;
    }
  }

  return 0;
}