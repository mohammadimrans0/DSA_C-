#include <iostream>
#include <queue>
using namespace std;

class node {
public:
  int data;
  node *left;
  node *right;

  node(int d) {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

node *buildTree(node *root) {
  int data;
  cin >> data;
  root = new node(data);

  if (data == -1) {
    return NULL;
  }

  root->left = buildTree(root->left);
  root->right = buildTree(root->right);

  return root;
}

void levelOrderTraversal(node *root) {
  queue<node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    node *temp = q.front();
    q.pop();

    if (temp == NULL) {
      // purana level complete traverse ho chuka hai
      cout << endl;
      if (!q.empty()) {
        // queue still has some child node
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if (temp->left) {
        q.push(temp->left);
      }

      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
}

void inOrder(node *root) {
  // base case
  if (root == NULL) {
    return;
  }

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void preorder(node *root) {
  // base case
  if (root == NULL) {
    return;
  }

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(node *root) {
  // base case
  if (root == NULL) {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

void buildFromLevelOrder(node *&root) {
  queue<node *> q;

  int data;
  cin >> data;
  root = new node(data);

  q.push(root);

  while (!q.empty()) {
    node *temp = q.front();
    q.pop();

    int leftData;
    cin >> leftData;

    if (leftData != -1) {
      temp->left = new node(leftData);
      q.push(temp->left);
    }

    int rightData;
    cin >> rightData;

    if (rightData != -1) {
      temp->right = new node(rightData);
      q.push(temp->right);
    }
  }
}

int main() {
  // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

  node *root = NULL;

  buildFromLevelOrder(root);
  levelOrderTraversal(root);

  
  //creating a Tree
  // root = buildTree(root);

  //level order
  // cout << "Printing the level order traversal output " << endl;
  // levelOrderTraversal(root);

  // cout << "inOrder traversal is:  ";
  // inOrder(root);

  // cout << endl << "preorder traversal is:  ";
  // preorder(root);

  // cout << endl << "postorder traversal is:  ";
  // postorder(root);

  return 0;
}