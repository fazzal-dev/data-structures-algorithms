#include "Node.h"
#include <iostream>
using namespace std;
void List::append(int data)
{
    if (size == 0)
    {
        m_Head->setData(data);
        m_Head->setLink(nullptr);
    }
    else
    {
        Node *newNode = new Node;
        newNode->setData(data);
        newNode->setLink(nullptr);
        m_Current->setLink(newNode);
        m_Current = newNode;
    }
    size++;
}
void List::insert(int data, int idx)
{
    if (idx > size)
    {
        throw out_of_range("Invalid Index!");
    }
    else if (idx == size)
    {
        append(data);
    }
    else
    {
        Node *newNode = new Node;
        Node *temp = m_Head;
        for (int i = 0; i < idx - 1; i++)
        {
            temp = temp->getLink();
        }
        newNode->setData(data);
        newNode->setLink(temp->getLink());
        temp->setLink(newNode);
        size++;
    }
}
void List::remove(int idx)
{
    if (idx < 0 || idx >= size)
    {
        throw out_of_range("Invalid Index!");
    }
    else if (idx == 0)
        removeFirst();
    else if (idx == size - 1)
        removeLast();
    else
    {
        Node *prev = m_Head;
        for (int i = 0; i < idx - 1; i++)
        {
            prev = prev->getLink();
        }
        Node *next = prev->getLink();
        prev->link = next->getLink();
        delete next;
    }
    size--;
}
void List::removeFirst()
{
    if (size == 0)
    {
        throw out_of_range("List is Empty");
    }
    else
    {
        Node *temp = m_Head;
        m_Head = m_Head->getLink();
        delete temp;
        size--;
    }
}
void List::removeLast()
{
    if (size > 1)
    {
        Node *prev = m_Head;
        Node *next = m_Head->getLink();
        while (next->getLink() != nullptr)
        {
            prev = prev->getLink();
            next = next->getLink();
        }
        prev->setLink(nullptr);
        delete next;
        size--;
    }
    else if (m_Head->getLink() == nullptr)
    {
        cout << "List has Only One Element!" << endl;
    }
    else
    {
        throw out_of_range("List is Empty!");
    }
}

void List::search(int data)
{
    Node *temp = m_Head;
    int index = 0;
    while (temp != nullptr)
    {
        if (temp->getData() == data)
        {
            cout << "Found at Index: " << index << endl;
            return;
        }
        temp = temp->getLink();
        index++;
    }
    cout << "Not Found" << endl;
}
int List::Size() { return size; }
void List::traverse()
{
    Node *temp = m_Head;
    while (temp)
    {
        cout << temp->getData() << " ";
        temp = temp->getLink();
    }
    cout << endl;
}