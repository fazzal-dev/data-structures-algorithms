#include "queue.h"
#include <iostream>
using namespace std;
int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();

    // cout<<q.peek()<<endl;
}