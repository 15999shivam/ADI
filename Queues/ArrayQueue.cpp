#include <iostream>
using namespace std;

class ArrayQueue
{
    int *arr;
    int size;
    // int front;
    int rear;

public:
    ArrayQueue(int size)
    {
        arr = new int[size];
        this->size = size;
        // front = -1;
        rear = -1;
    }

    int peek()
    {
        if (rear != -1)
            return arr[0];
        return -1;
    }

    void push(int val)
    {
        if (rear + 1 != size)
        {
            arr[++rear] = val;
        }
        else
        {
            cout << "queue is full yr" << endl;
        }
    }

    int front()
    {
        return arr[0];
    }

    int pop()
    {
        if (rear != -1)
        {
            for (int i = 1; i <= rear; i++)
            {
                arr[i - 1] = arr[i];
            }
            rear = rear - 1;
        }
        else
        {
            cout << "queue is already empty" << endl;
        }
    }
    int isEmpty()
    {
        return rear == -1;
    }

    //display
    void display()
    {
        if (rear == -1)
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    ArrayQueue q(4);

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