#include <iostream>
#include "stack.h"
int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.display();
    // std::cout<<s1.top()<<std::endl;
    // s1.pop();
    // std::cout<<s1.top()<<std::endl;

    return 0;
}
