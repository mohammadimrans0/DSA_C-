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

bool isPalindrome(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return true;

  Node *left = head;
  Node *right = head;

  while (right->next != nullptr)
    right = right->next;

  while (left != right && left->prev != right) {
    if (left->value != right->value)
      return false;
    left = left->next;
    right = right->prev;
  }

  return true;
}

Node *createDoublyLinkedList() {
  Node *head = nullptr;
  Node *tail = nullptr;

  int value;
  cin >> value;

  while (value != -1) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    cin >> value;
  }

  return head;
}

int main() {

  Node *head = createDoublyLinkedList();

  if (isPalindrome(head))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
