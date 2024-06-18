/*
You will be given a binary tree as input in level order. You need to tell if the
binary tree is perfect or not. A binary tree is called perfect if all leaf nodes
are at the maximum depth of the tree, and the tree is completely filled with no
gaps.
*/

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

Node *input_binary_tree() {
  int val;
  cin >> val;
  Node *root;

  if (val == -1) {
    root = NULL;
  } else {
    root = new Node(val);
  }

  queue<Node *> q;
  if (root) {
    q.push(root);
  }

  while (!q.empty()) {
    // 1. ber kore ano
    Node *p = q.front();
    q.pop();

    // 2. jabotiyo ja kaj ache
    int l, r;
    cin >> l >> r;

    Node *myLeft;
    Node *myRight;

    if (l == -1) {
      myLeft = NULL;
    } else {
      myLeft = new Node(l);
    }

    if (r == -1) {
      myRight = NULL;
    } else {
      myRight = new Node(r);
    }

    p->left = myLeft;
    p->right = myRight;

    // 3. children gulo ke push koro
    if (p->left)
      q.push(p->left);
    if (p->right)
      q.push(p->right);
  }
  return root;
}

int countNode(Node *root) {
  if (root == nullptr)
    return 0;

  int l = countNode(root->left);
  int r = countNode(root->right);

  return l + r + 1;
}

int maxHeight(Node *root) {
  if (root == nullptr)
    return 0;

  int l = maxHeight(root->left);
  int r = maxHeight(root->right);

  return max(l, r) + 1;
}

int main() {
  Node *root = input_binary_tree();

  int totalNode = countNode(root);
  int depth = maxHeight(root);

  if (pow(2, depth) - 1 == totalNode) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}