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
    cout << endl << "Inserted at head" << endl << endl;
    return;
  }

  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  // temp is now in the last node.

  temp->next = newNode;
  cout << endl << "Inserted at tail" << endl << endl;
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
    if(temp == NULL){
      cout << endl
           << "Invalid Position" << endl
           << endl;
      return;
    }
  }
  newNode->next = temp->next;
  temp->next = newNode;

  cout << endl << "Inserted at position " << pos << endl << endl;
}

void insert_at_head(Node *&head, int v) {
  Node *newNode = new Node(v);
  newNode->next = head;
  head = newNode;
  cout << endl << "Inserted at head" << endl << endl;
}

void delete_from_position(Node *head, int pos) {
  Node *tmp = head;
  for (int i = 1; i < pos - 1; i++) {
    tmp = tmp->next;
    if (tmp == NULL) {
      cout << endl << "Invalid Position" << endl << endl;
      return;
    }
  }
  if(tmp->next == NULL){
    cout << endl << "Invalid Position" << endl << endl;
    return;
  }
  Node *deleteNode = tmp->next;
  tmp->next = tmp->next->next;
  delete deleteNode;
  cout << endl << "Delete position " << pos << endl << endl;
}

void delete_head(Node *&head) {
  Node *deleteNode = head;
  head = head->next;
  delete deleteNode;
  cout << endl << "Delete head" << endl << endl;
}

int main() {

  Node *head = NULL;
  while (true) {
    cout << "option 1: Insert at Tail" << endl;
    cout << "option 2: Print linked list" << endl;
    cout << "option 3: Insert at any position" << endl; // error handled
    cout << "option 4: Insert at head" << endl;
    cout << "option 5: Delete from position" << endl; // error handled
    cout << "option 6: Delete head" << endl;
    cout << "option 7: Terminate" << endl;

    int opt;
    cin >> opt;

    if (opt == 1) {
      cout << "Please enter value: ";
      int value;
      cin >> value;
      insert_at_tail(head, value);
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
      int pos;
      cout << "Enter Position: ";
      cin >> pos;
      if (pos == 1) {
        delete_head(head);
      } else {
        delete_from_position(head, pos);
      }

    } else if (opt == 6) {
      delete_head(head);
    } else if (opt == 7) {
      break;
    }
  }

  return 0;
}