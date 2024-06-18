/*
You will be given a binary tree as input in level order. Also you will be given
a level . You need to print all the node's values in that level from left to
right. Assume that level starts from 0.
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

void printNodeAtLevel(Node *root, int level) {
  if (root == nullptr || level < 0) {
    cout << "Invalid";
    return;
  }

  queue<Node *> q;
  q.push(root);

  int currentLevel = 0;

  while (!q.empty() && currentLevel <= level) {
    int nodesInCurrentLevel = q.size();

    if (currentLevel == level) {
      while (nodesInCurrentLevel--) {
        Node *p = q.front();
        q.pop();
        cout << p->val << " ";
      }
      return;
    }

    while (nodesInCurrentLevel--) {
      Node *p = q.front();
      q.pop();
      if (p->left != nullptr)
        q.push(p->left);
      if (p->right != nullptr)
        q.push(p->right);
    }
    ++currentLevel;
  }
  cout << "Invalid";
}

int main() {
  Node *root = input_binary_tree();

  int level;
  cin >> level;
  printNodeAtLevel(root, level);

  return 0;
}