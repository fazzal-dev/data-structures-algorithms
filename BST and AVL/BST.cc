#include "TreeNode.h"

BST::BST() : m_root(nullptr) {}
TreeNode::TreeNode() : data(0), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int64_t _data) : data(_data), left(nullptr), right(nullptr) {}

bool BST::isEmpty()
{
    if (m_root == nullptr)
        return true;
    else
        return false;
}
TreeNode *BST::getRoot() { return this->m_root; }

void BST::append(int64_t _data)
{
    TreeNode *newNode = getNode(_data);

    if (m_root == nullptr)
    {
        m_root = newNode;
        return;
    }
    TreeNode *cursor = m_root;
    while (cursor)
    {
        if (cursor->data == newNode->data)
        {
            std::cout << "Already Exist!" << std::endl;
            return;
        }
        else if (_data < cursor->data)
        {
            if (cursor->left == nullptr)
            {
                cursor->left = newNode;
                return;
            }
            cursor = cursor->left;
        }
        else
        {
            if (cursor->right == nullptr)
            {
                cursor->right = newNode;
                return;
            }
            cursor = cursor->right;
        }
    }
}

TreeNode *BST::deleteNode(TreeNode *_root, int64_t _data)
{
    if (this->Search(_data))
    {
        if (_root == nullptr)
            return _root;
        else if (_data < _root->data) // if value is smaller go left
            _root->left = deleteNode(_root->left, _data);
        else if (_data > _root->data) // if value is greater go right
            _root->right = deleteNode(_root->right, _data);
        else // if the value is found
        {
            if (_root->left == nullptr) // node with only one child OR no Child
            {
                TreeNode *s_right = _root->right;
                delete _root;
                return s_right;
            }
            else if (_root->right == nullptr) // node with only left child
            {

                TreeNode *s_left = _root->left;
                delete _root;
                return s_left;
            }
            else // node with two child
            {
                TreeNode *s_Min{minVal(_root->right)};
                _root->data = s_Min->data;
                _root->right = deleteNode(_root->right, s_Min->data);
            }
        }
    }
    else
    {
        std::cout << "Element Not Found!" << std::endl;
    }
    return _root;
}

TreeNode *BST::BalanceTheTreeAfterDeletion(TreeNode *_root)
{
    int32_t balanceFactor = getBalanceFactor(_root);
    if (balanceFactor == 2 && getBalanceFactor(_root->left) >= 0)
        return rightRotate(_root);
    else if (balanceFactor == 2 && getBalanceFactor(_root->left) == -1)
    {
        _root->left = leftRotate(_root);
        return rightRotate(_root);
    }
    else if (balanceFactor == -2 && getBalanceFactor(_root->right) <= 0)
        return leftRotate(_root);
    else if (balanceFactor == -2 && getBalanceFactor(_root->right) == 1)
    {
        _root->right = rightRotate(_root->right);
        return leftRotate(_root);
    }
    return EXIT_SUCCESS;
}

TreeNode *BST::Search(int64_t _data)
{
    if (m_root == nullptr)
    {
        return m_root;
    }
    else
    {
        TreeNode *temp = m_root;
        while (temp != NULL)
        {
            if (_data == temp->data)
            {
                return temp;
            }
            else if (_data < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return nullptr;
    }
}

TreeNode *BST::minVal(TreeNode *_root)
{

    TreeNode *curr{_root};
    while (curr->left)
    {
        curr = curr->left;
    }
    return curr;
}

int BST::getBalanceFactor(TreeNode *_root)
{
    if (_root == nullptr)
        return -1;
    else
    {
        return (height(_root->left) - height(_root->right));
    }
}

TreeNode *BST::rightRotate(TreeNode *node)
{
    TreeNode *storeLeft = node->left;
    TreeNode *storeRight = storeLeft->right;
    // perforom Rotation
    storeLeft->right = node;
    node->left = storeRight;
    return storeLeft;
}

TreeNode *BST::leftRotate(TreeNode *node)
{
    TreeNode *storeRight = node->right;
    TreeNode *storeleft = storeRight->left;
    // perforom Rotation
    storeRight->left = node;
    node->right = storeleft;
    return storeRight;
}

int BST::height(TreeNode *_root)
{
    if (not _root)
        return -1;
    else
    {
        int lheight = height(_root->left);
        int rheight = height(_root->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

TreeNode *BST::getNode(int64_t _data)
{
    TreeNode *newNode = new TreeNode{_data};
    return newNode;
}

TreeNode *BST::balanceTheFreakingTree(TreeNode *_root, TreeNode *newNode)
{

    int32_t balanceFactor = getBalanceFactor(_root);
    // Left rotate case
    if (balanceFactor > 1 && newNode->data < _root->left->data)
        return rightRotate(_root);
    // Right rotate case
    if (balanceFactor < -1 && newNode->data > _root->right->data)
        return leftRotate(_root);
    // Left Right Case
    if (balanceFactor > 1 && newNode->data > _root->left->data)
    {
        _root->left = leftRotate(_root->left);
        return rightRotate(_root);
    }
    // Right Left Case
    if (balanceFactor < -1 && newNode->data < _root->right->data)
    {
        _root->right = rightRotate(_root->right);
        return leftRotate(_root);
    }
    return _root;
}

void BST::preOrder(TreeNode *_root)
{
    if (not _root)
        return;
    std::cout << _root->data << ' ';
    preOrder(_root->left);
    preOrder(_root->right);
}

void BST::inOrder(TreeNode *_root)
{
    if (not _root)
        return;
    inOrder(_root->left);
    std::cout << _root->data << ' ';
    inOrder(_root->right);
}

void BST::postOrder(TreeNode *_root)
{
    if (not _root)
        return;
    postOrder(_root->left);
    postOrder(_root->right);
    std::cout << _root->data << ' ';
}
