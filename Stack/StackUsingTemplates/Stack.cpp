#include <iostream>
using namespace std;

template <class type>
class Stack
{
    int stackSize;
    int stackTop;
    type *list;

public:
    Stack() : stackTop(-1), stackSize(100), list(new type[stackSize]) {}
    bool isEmptyStack();
    bool isFullStack();
    void push(type data);
    type top();
    void pop();
    void display();
};

template <class type>
bool Stack<type>::isEmptyStack()
{
    return (stackTop == -1);
}

template <class type>
bool Stack<type>::isFullStack()
{
    return (stackTop == stackSize);
}

template <class type>
void Stack<type>::push(type data)
{
    if (!isFullStack())
    {
        list[++stackTop] = data;
    }
    else
        cout << "Stack is Full!" << endl;
}

template <class type>
void Stack<type>::pop()
{
    if (!isEmptyStack())
    {
        list[stackTop--];
    }
    else
        cout << "Cannot Pop from an Empty Stack!";
}

template <class type>
type Stack<type>::top()
{
    type top_element = list[stackTop];
    return top_element;
}

template <class type>
void Stack<type>::display()
{

    for (int i = stackTop; i >= 0; i--)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main()
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.display();
    std::cout << s1.top() << std::endl;

    Stack<string> str;
    str.push("world");
    str.push("Hello");
    str.display();
    str.pop();
    str.display();
    // s1.display();

    // std::cout<<s1.top()<<std::endl;
    // s1.pop();
    // std::cout<<s1.top()<<std::endl;

    return 0;
}
