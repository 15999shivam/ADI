//https://www.youtube.com/watch?v=DxW7VAsdX0o
#include <iostream>
using namespace std;

class MultiStack
{
    int *arr;
    int top;
    int bottom;
    int size;

public:
    MultiStack(int size)
    {
        arr = new int[size];
        top = -1;
        bottom = size;
        this->size = size;
    }

    void push(int stack, int n)
    {
        if (stack == 1)
        {
            if (bottom != 0 && (bottom - 1) != top)
            {
                arr[--bottom] = n;
                // cout << "\npush bottom: " << bottom << endl;
            }
            else
            {
                cout << "can not insert stack full " << stack << endl;
            }
        }
        else
        {
            // cout << "hii in function" << endl;
            if (top + 1 != size && (top + 1) != bottom)
            {
                // cout << "inside if" << endl;
                arr[++top] = n;
            }
            else
            {
                // cout << "inside else" << endl;
                cout << "can not insert stack full " << stack << endl;
            }
        }
    }

    int peek(int stack)
    {
        if (stack == 0)
        {
            return arr[top];
        }
        // cout << "\nbottom: " << bottom << endl;
        return arr[bottom];
    }

    void pop(int stack)
    {
        if (stack == 0)
        {
            top--;
            return;
        }
        bottom++;
    }

    int isEmpty(int stack)
    {
        if (stack == 0)
        {
            return (top == -1);
        }
        return (bottom == size);
    }
};

int main()
{

    MultiStack stack(10);

    stack.push(0, 1);
    stack.push(0, 2);
    stack.push(0, 3);
    stack.push(0, 3);
    stack.push(0, 4);
    stack.push(0, 5);
    stack.push(1, 1);
    stack.push(1, 2);
    stack.push(1, 3);
    stack.push(1, 4);
    stack.push(1, 5);
    stack.push(0, 5);

    while (!stack.isEmpty(0))
    {
        cout << stack.peek(0) << endl;
        stack.pop(0);
    }

    cout << "Stack 1" << endl;

    while (!stack.isEmpty(1))
    {
        cout << stack.peek(1) << endl;
        stack.pop(1);
    }

    return 0;
}