#include "node.hpp"
void BinaryTree::insert(int val)
{
  TreeNode *new_node = new TreeNode(val);
  if (root_ == nullptr)
  {
    root_ = new_node;
    return;
  }
  TreeNode *curr = root_;
  while (true)
  {
    if (val < curr->val)
    {
      if (curr->left == nullptr)
      {
        curr->left = new_node;
        return;
      }
      curr = curr->left;
    }
    else
    {
      if (curr->right == nullptr)
      {
        curr->right = new_node;
        return;
      }
      curr = curr->right;
    }
  }
}
void BinaryTree::preOrder(TreeNode *root)
{
  if (root == nullptr)
    return;
  std::cout << root->val << " ";
  preOrder(root->left);
  preOrder(root->right);
}
void BinaryTree::inOrder(TreeNode *root)
{
  if (root == nullptr)
    return;
  inOrder(root->left);
  std::cout << root->val << " ";
  inOrder(root->right);
}
void BinaryTree::postOrder(TreeNode *root)
{
  if (root == nullptr)
    return;
  postOrder(root->left);
  postOrder(root->right);
  std::cout << root->val << " ";
}