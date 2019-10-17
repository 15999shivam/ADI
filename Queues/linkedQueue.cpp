#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class LinkedQueue
{
    node *queue;
    node *tail;

public:
    LinkedQueue()
    {
        queue = NULL;
        tail = NULL;
    }

    int peek()
    {
        if (queue != NULL)
        {
            return queue->data;
        }
        return -1;
    }

    void push(int val)
    {

        node *temp = new node;
        temp->data = val;
        temp->next = NULL;
        if (queue == NULL)
        {
            queue = temp;
            tail = queue;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    int front()
    {
        if (queue != NULL)
        {
            return queue->data;
        }
        return -1;
    }

    int pop()
    {
        if (queue != NULL)
        {
            if (queue->next == NULL)
            {
                queue = NULL;
                tail = NULL;
            }
            else
            {
                queue = queue->next;
            }
        }
        else
        {
            cout << "queue is already empty" << endl;
        }
    }
    int isEmpty()
    {
        return queue == NULL;
    }

    //display
    void display()
    {
        if (queue == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        node *temp = queue;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    LinkedQueue q;

    // print Queue elements
    q.display();

    // inserting elements in the queue
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // print Queue elements
    q.display();

    // insert element in the queue
    q.push(60);

    // print Queue elements
    q.display();

    q.pop();
    q.pop();

    cout << "\n\nafter two node deletion\n\n";

    // print Queue elements
    q.display();

    // print front of the queue
    cout << q.peek();

    return 0;
}