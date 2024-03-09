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
  cout << endl;
  cout << "your linked list: ";
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl << endl;
}

void insert_at_position(Node *head, int pos, int v) {
  Node *newNode = new Node(v);

  Node *temp = head;
  for (int i = 1; i < pos - 1; i++) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;

  cout << endl << "Inserted at position" << endl << endl;
}

void insert_at_head(Node *&head, int v) {
  Node *newNode = new Node(v);
  newNode->next = head;
  head = newNode;
  cout << endl << "Inserted at head" << endl << endl;
}

int main() {

  Node *head = NULL;
  Node *tail = NULL;
  while (true) {
    cout << "option 1: Insert at Tail" << endl;
    cout << "option 2: Print linked list" << endl;
    cout << "option 3: Insert at any position" << endl;
    cout << "option 4: Insert at head" << endl;
    cout << "option 5: Terminate" << endl;
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
      int position, v;
      cout << "Enter position: ";
      cin >> position;
      cout << "Enter value: ";
      cin >> v;

      if (position == 0) {
        insert_at_head(head, v);
      } else {
        insert_at_position(head, position, v);
      }

    } else if (opt == 4) {
      int v;
      cout << "Enter value: ";
      cin >> v;
      insert_at_head(head, v);
    } else if (opt == 5) {
      break;
    }
  }

  return 0;
}