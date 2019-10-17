#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
    queue<int> q1, q2;

public:
    void push(int n)
    {
        q1.push(n);
    }

    int peek()
    {
        if (q1.empty())
        {
            return -1;
        }

        //transfer all value except one to q2
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        //last value is what i need
        int temp = q1.front();
        q1.pop();

        //make q2 as previously q1 was
        q2.push(temp);

        //swap the values to get to the same ground
        queue<int> q = q1;
        q1 = q2;
        q2 = q;

        return temp;
    }

    void pop()
    {
        if (q1.empty())
        {
            return;
        }

        //transfer all value except one to q2
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        //remove the element
        q1.pop();

        //swap the values to get to the same ground
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    int isEmpty()
    {
        return q1.empty();
    }
};

int main()
{
    QueueStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    // cout << "peek" << stack.peek() << endl;
    stack.pop();
    stack.push(6);

    //printstack
    while (!stack.isEmpty())
    {
        cout << stack.peek() << endl;
        stack.pop();
    }
}