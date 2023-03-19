#include <iostream>
using namespace std;
class queue
{
    int front, back;
    int m_size;
    int *m_array;

public:
    queue() : front(-1), back(-1), m_size(10), m_array(new int[m_size]) {}
    void enqueue(int data);
    void dequeue();
    int peek();
    bool isEmpty();
    void display();
};
void queue::enqueue(int data)
{
    if (front == -1)
    {
        front++;
    }
    if (back == m_size - 1)
    {
        cout << "Queue Overflow!" << endl;
        return;
    }
    else
        m_array[++back] = data;
}
void queue::dequeue()
{
    if (!isEmpty())
        front++;
}
bool queue::isEmpty()
{
    if (front == -1 || front > back)
        return 1;
    return 0;
}
int queue::peek()
{
    if (!isEmpty())
        return m_array[front];
}
void queue::display()
{
    for (int i = front; i <= back; i++)
    {
        cout << m_array[i] << " ";
    }
    cout << endl;
}
int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();

    q.dequeue();
    q.display();
    return 0;
}