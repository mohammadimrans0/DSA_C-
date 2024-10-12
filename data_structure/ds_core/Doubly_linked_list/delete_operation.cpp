#include <bits/stdc++.h>
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

int size(Node *head) {
  Node *tmp = head;
  int cnt = 0;
  while (tmp != nullptr) {
    cnt++;
    tmp = tmp->next;
  }
  return cnt;
}

void delete_at_position(Node * head, int pos){
    Node *tmp = head;
    for (int i = 0; i <= pos;i++){
        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete deleteNode;
}

void delete_tail(Node *&head ,Node *&tail){
    Node *deleteNode = tail;
    tail = tail->prev;
    delete deleteNode;

    if(tail == nullptr){
      head = nullptr;
      return;
    }
    tail->next = nullptr;
}

void delete_head(Node *&head, Node *&tail){
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;

    if(head == nullptr){
      tail = nullptr;
      return;
    }
    head->prev = nullptr;
}


int main() {

  //   Node *head = nullptr;
  //   Node *tail = nullptr;

  Node *head = new Node(10);
  Node *a = new Node(20);
  Node *b = new Node(30);
  Node *c = new Node(40);
  Node *tail = c;

  // connection
  head->next = a;
  a->prev = head;
  a->next = b;
  b->prev = a;
  b->next = c;
  c->prev = b;

  int pos;
  cin >> pos;

  if(pos >= size(head)){
      cout << "Invalid" << endl;
  }else if (pos == 0)
  {
    delete_head(head, tail);
  }else if (pos == size(head) - 1)
  {
    delete_tail(head, tail);
  }else{
    delete_at_position(head, pos);
  }

  print_forward(head);
  print_backward(tail);

  return 0;
}