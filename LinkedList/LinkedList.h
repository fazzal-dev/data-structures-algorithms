class Node
{
public:
    int data;
    Node *link;
    int getData() { return data; };
    void setData(int data) { this->data = data; }
    Node *getLink() { return link; }
    void setLink(Node *link) { this->link = link; }
};
class List
{
public:
    List() : m_Head(new Node), m_Current(m_Head), size(0) {}

    void append(int data);
    void insert(int data, int idx);
    void remove(int idx);
    void search(int data);
    void traverse();
    void removeLast();
    void removeFirst();
    int Size();

private:
    Node *m_Head, *m_Current;
    int size;
};