#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class LinkedQueue
{
    stack<int> s1, s2;

public:
    void push(int val)
    {
        s1.push(val);
    }

    int front()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    }

    int pop()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
    }
    int isEmpty()
    {
        return (s1.empty() && s2.empty());
    }

    //display
    void display()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        // while (!s1.empty())
        // {
        //     s2.push(s1.top());
        //     s1.pop();
        // }

        stack<int> temp = s2;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        temp = s1;
        stack<int> temp2;

        while (!temp.empty())
        {
            temp2.push(temp.top());
            temp.pop();
        }
        while (!temp2.empty())
        {
            cout << temp2.top() << " ";
            temp2.pop();
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
    cout << q.front();

    return 0;
}