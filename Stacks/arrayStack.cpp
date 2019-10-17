#include <iostream>
using namespace std;

class ArrayStack
{
    int *arr;
    int top;
    int size;

public:
    ArrayStack(int size)
    {
        arr = new int[size];
        top = -1;
        this->size = size;
    }

    void push(int n)
    {
        if (top + 1 != size)
        {
            arr[++top] = n;
        }
        else
        {
            cout << "can not insert stack full";
        }
    }

    int peek()
    {
        return arr[top];
    }

    void pop()
    {
        top--;
    }

    int isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    ArrayStack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.pop();
    stack.push(6);

    //printstack
    while (!stack.isEmpty())
    {
        cout << stack.peek() << endl;
        stack.pop();
    }
}