#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); ++i) {
      inorderMap[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
  }

  TreeNode *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
                            vector<int> &inorder, int inStart, int inEnd,
                            unordered_map<int, int> &inorderMap) {
    if (preStart > preEnd || inStart > inEnd)
      return nullptr;

    int rootValue = preorder[preStart];
    TreeNode *root = new TreeNode(rootValue);

    int rootIndexInorder = inorderMap[rootValue];
    int leftSubtreeSize = rootIndexInorder - inStart;

    root->left =
        buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize,
                        inorder, inStart, rootIndexInorder - 1, inorderMap);
    root->right =
        buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd,
                        inorder, rootIndexInorder + 1, inEnd, inorderMap);

    return root;
  }
};

// Function to print the inorder traversal of a binary tree
void printInorder(TreeNode *node) {
  if (node == nullptr)
    return;
  printInorder(node->left);
  cout << node->val << " ";
  printInorder(node->right);
}

int main() {
  Solution solution;

  // Example input
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};

  TreeNode *root = solution.buildTree(preorder, inorder);

  // Printing the inorder traversal of the constructed tree
  cout << "Inorder traversal of the constructed tree: ";
  printInorder(root);
  cout << endl;

  return 0;
}
