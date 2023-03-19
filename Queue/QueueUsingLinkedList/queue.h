class node
{
public:
    int data;
    node *next;
};
class queue
{
    node *front, *back;

public:
    queue() : front(nullptr), back(nullptr) {}
    void enqueue(int data);
    void dequeue();
    int peek();
    bool isEmpty();
    void display();
};