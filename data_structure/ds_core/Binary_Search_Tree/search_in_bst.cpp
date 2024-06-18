#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node(int val) {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *insert_bst(Node *root, int value) {
  if (root == nullptr) {
    return new Node(value);
  }

  if (value < root->val) {
    root->left = insert_bst(root->left, value);
  } else {
    root->right = insert_bst(root->right, value);
  }

  return root;
}

bool bst(Node *root, int x) {
  if (root == nullptr)
    return false;
  if (root->val == x)
    return true;
  if (x < root->val) {
    return bst(root->left, x);
  }else{
      return bst(root->right, x);
  }
}

int main() {
  Node *root = nullptr;

  int data;
  cin >> data;

  while (data != -1) {
    root = insert_bst(root, data);
    cin >> data;
  }

  if(bst(root, 8))
      cout << "Yes Found";
    else
        cout << "Not Found";

  return 0;
}