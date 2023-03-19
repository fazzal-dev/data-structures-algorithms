#include <iostream>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
  BinaryTree() : root_(nullptr) {}

  void insert(int val);
  void inOrder() { inOrder(root_); }     // left, root, right
  void preOrder() { preOrder(root_); }   // root, left, right
  void postOrder() { postOrder(root_); } // left, right, root
  TreeNode *root() { return root_; }

private:
  void preOrder(TreeNode *root);
  void inOrder(TreeNode *root);
  void postOrder(TreeNode *root);
  TreeNode *root_;
};
