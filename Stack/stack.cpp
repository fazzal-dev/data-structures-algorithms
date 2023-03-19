#include "stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

bool Stack::isEmptyStack()
{
    return (stackTop == -1);
}

bool Stack::isFullStack()
{
    return (stackTop == stackSize);
}

void Stack::push(int data)
{
    if (!isFullStack())
    {
        list[++stackTop] = data;
    }
    else
        cout << "Stack is Full!" << endl;
}

void Stack::pop()
{
    if (!isEmptyStack())
    {
        list[stackTop--];
    }
    else
        cout << "Cannot Pop from an Empty Stack!";
}

int Stack::top()
{
    int top_element = list[stackTop - 1];
    return top_element;
}

void Stack::display()
{

    for (int i = stackTop; i >= 0; i--)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
