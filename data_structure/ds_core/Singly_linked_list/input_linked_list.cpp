#include<bits/stdc++.h>
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
  cout << "your linked list:" << endl;
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}

void print_reverse_linked_list(Node *n){
  // base case
  if (n == NULL)
    return;

  print_reverse_linked_list(n->next);
  cout << n->value << " ";
}

int main(){
    int value;
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        cin >> value;
        if(value == -1) break;
        insert_at_tail(head, tail, value);
    }

    print_linked_list(head);

    cout << "your reverse linked list:"<< endl;
    print_reverse_linked_list(head);
    
    return 0;
}