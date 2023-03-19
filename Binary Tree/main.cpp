#include <iostream>
#include "node.hpp"

int main()
{
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    std::cout << "\nPre-order traversal: ";
    tree.preOrder();
    std::cout << "\nIn-order traversal: ";
    tree.inOrder();
    std::cout << "\nPost-order traversal: ";
    tree.postOrder();
    return 0;
}