#include <iostream>
using namespace std;

class list
{
    struct Node
    {
        int data;
        Node *next;
    };
    Node *stackTop;
    int stackSize;

public:
    list() : stackTop(nullptr), stackSize(0) {}
    bool isEmptyStack();
    void push(int data);
    int peek();
    int peek(int idx);
    void pop();
    int st_size();
    void traverse();
};

bool list::isEmptyStack()
{
    if (stackTop == nullptr)
        return 1;
    else
        return 0;
}

void list::push(int data)
{

    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = stackTop;
    stackTop = newNode;
    stackSize++;
}

void list::pop()
{
    if (!isEmptyStack())
    {
        Node *tempo = stackTop;
        stackTop = stackTop->next;
        delete tempo;
        stackSize--;
    }
    else
        cout << "Stack Underflow" << endl;
}

void list::traverse()
{
    Node *temp = stackTop;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int list::peek()
{
    if (stackTop == nullptr)
    {
        cout << "Stack is Empty!" << endl;
    }
    return stackTop->data;
}

int list::peek(int idx)
{
    Node *temp = stackTop;
    for (int i = 0; (i < idx - 1 && temp != nullptr); i++)
    {
        temp = temp->next;
    }
    if (temp != nullptr)
    {
        return temp->data;
    }
    else
        cout << "Invalid Index!" << endl;
}

int list::st_size()
{
    return stackSize;
}

int main()
{
    list l;
    l.push(8);
    l.push(5);
    l.push(9);
    l.push(10);
    // l.pop();
    l.traverse();

    return 0;
}