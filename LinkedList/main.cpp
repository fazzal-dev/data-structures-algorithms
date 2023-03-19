#include <iostream>
#include "Node.h"
int main()
{
    List l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);
    // l.remove(2);
    // l.search(5);
    l.traverse();
    std::cout << "Size of List: " << l.Size() << std::endl;
    return 0;
}