#include "queue.h"
#include <iostream>
using namespace std;
void queue::enqueue(int data)
{

    node *newNode = new node;
    if (front == nullptr)
    {
        front = newNode;
        back = newNode;
        newNode->data = data;
        newNode->next = nullptr;
    }
    else
    {
        newNode->data = data;
        back->next = newNode;
        back = newNode;
        newNode->next = nullptr;
    }
}
void queue::dequeue()
{
    if (!isEmpty())
    {
        node *temp = front;
        front = temp->next;
        delete temp;
    }
    else
        cout << "Queue is Empty!" << endl;
}
bool queue::isEmpty()
{
    if (front == nullptr)
        return 1;
    return 0;
}
int queue::peek()
{
    return front->data;
}
void queue::display()
{
    node *temp = front;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
