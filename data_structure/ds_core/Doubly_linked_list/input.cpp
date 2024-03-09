#include<bits/stdc++.h>
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

void print_backward(Node *tail) {
  Node *tmp = tail;
  while (tmp != nullptr) {
    cout << tmp->value << " ";
    tmp = tmp->prev;
  }
  cout << endl;
}

void insert_tail(Node *&head, Node *&tail, int val) {
  Node *newNode = new Node(val);
  if (tail == nullptr) {
    head = newNode;
    tail = newNode;
    return;
  }

  tail->next = newNode;
  newNode->prev = tail;
  tail = tail->next;
}

int main(){

    Node *head = nullptr;
    Node *tail = nullptr;
    int val;
    while (true)
    {
        cin >> val;
        if(val == -1) break;
        insert_tail(head, tail, val);
    }

    print_forward(head);
    print_backward(tail);

    return 0;
}