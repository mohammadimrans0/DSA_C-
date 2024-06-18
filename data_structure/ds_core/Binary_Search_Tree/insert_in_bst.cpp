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

void print_level_order(Node *root) {
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();

    if (temp == NULL) {
      // purana level complete traverse ho chuka hai
      cout << endl;
      if (!q.empty()) {
        // queue still has some child node
        q.push(NULL);
      }
    } else {
      cout << temp->val << " ";
      if (temp->left) {
        q.push(temp->left);
      }

      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
}

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

int main() {
  Node *root = nullptr;

  int data;
  cin >> data;

  while(data != -1){
    root = insert_bst(root, data);
    cin >> data;
  }

  print_level_order(root);

  return 0;
}