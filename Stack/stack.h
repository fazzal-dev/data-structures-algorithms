#include <cstdlib>

class Stack
{
public:
        Stack() : stackTop(-1), stackSize(100), list(new int[stackSize]) {}
        bool isEmptyStack();
        bool isFullStack();
        void push(int data);
        int top();
        void pop();
        void display();

private:
        int stackSize;
        int stackTop;
        int *list;
};
