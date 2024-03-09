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

void print_forward(Node *head){
    Node *tmp = head;
    while (tmp != nullptr){
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_backward(Node *tail){
    Node *tmp = tail;
    while (tmp != nullptr){
        cout << tmp->value << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

int main(){

    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = b;

    // connection
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;

    print_forward(head);
    print_backward(tail);

    return 0;
}