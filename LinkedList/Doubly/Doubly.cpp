#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
class list
{
private:
    Node *m_head, *m_current;
    int Size;

public:
    list() : m_head(new Node), m_current(m_head), Size(0) {}
    void add(int data);
    void add(int data, int idx);
    void traverse();
    void revtraverse();
    int size();
};
void list::add(int data)
{
    if (Size == 0)
    {
        m_head->data = data;
        m_head->next = nullptr;
        m_head->prev = nullptr;
    }
    else
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        m_current->next = newNode;
        newNode->prev = m_current;
        m_current = newNode;
    }
    Size++;
}
void list::add(int data, int idx)
{
    Node *newNode = new Node;
    if (idx == 0 && !Size)
    {
        newNode->data = data;
        newNode->next = m_head;
        m_head->prev = newNode;
        m_head = newNode;
        m_head->prev = nullptr;
    }
    else if ((idx < (Size / 2)))
    {

        Node *temp = m_head;
        for (int i = 1; i < idx - 1; i++)
        {
            temp = temp->next;
        }
        Node *ptr = temp->next;
        newNode->data = data;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = ptr;
        ptr->prev = newNode;
    }
    else
    {
        Node *temp = m_current;
        for (int i = Size - 1; i > idx; i--)
        {
            temp = temp->prev;
        }
        Node *ptr = temp->prev;
        newNode->data = data;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = ptr;
        ptr->next = newNode;
    }
    Size++;
}
void list::traverse()
{
    Node *temp = m_head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void list::revtraverse()
{
    Node *temp = m_current;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
int list::size() { return Size; }
int main()
{
    list l1;
    l1.add(1);
    l1.add(2);
    l1.add(4);
    l1.add(5);
    l1.add(6);
    l1.add(3, 0);
    l1.traverse();
    l1.revtraverse();
    cout << "Size of List: " << l1.size() << endl;

    return 0;
}