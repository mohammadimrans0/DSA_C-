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

  int min = INT_MAX;
  int max = INT_MIN;

  for (Node *i = head; i != NULL; i = i->next) {
    if(i->value > max){
        max = i->value;
    }

    if(i->value < min){
        min = i->value;
    }
  }

  cout << max-min << endl;

  return 0;
}