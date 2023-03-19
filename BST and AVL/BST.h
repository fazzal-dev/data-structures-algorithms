#include <iostream>
struct TreeNode
{
    int64_t data;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(int64_t);
};

class BST
{
public:
    BST();
    bool isEmpty();
    void append(int64_t _data);
    TreeNode *Search(int64_t _data);
    TreeNode *deleteNode(TreeNode *_root, int64_t _data);

    void preOrder(TreeNode *_root);
    void postOrder(TreeNode *_root);
    void inOrder(TreeNode *_root);

    TreeNode *getRoot();
    TreeNode *minVal(TreeNode *_root);

    // for AVL tree implementation
    TreeNode *balanceTheFreakingTree(TreeNode *_root, TreeNode *newNode);
    TreeNode *BalanceTheTreeAfterDeletion(TreeNode *_root);
    int getBalanceFactor(TreeNode *_root);
    int height(TreeNode *_root);
    TreeNode *getNode(int64_t _data);
    TreeNode *rightRotate(TreeNode *node);
    TreeNode *leftRotate(TreeNode *node);

private:
    TreeNode *m_root;
};
