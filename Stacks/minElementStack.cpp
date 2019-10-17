#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class LinkedStack
{
    node *list;
    int min;

public:
    LinkedStack()
    {
        list = NULL;
    }

    void push(int n)
    {
        node *temp = new node;
        temp->data = n;
        if (list == NULL)
        {
            list = temp;
            min = n;
            list->next = NULL;
        }
        else
        {
            if (n > min)
            {
                temp->next = list;
            }
            else
            {
                temp->data = 2 * n - min;
                min = n;
            }

            list = temp;
        }
    }

    int peek()
    {
        return list->data < min ? min : list->data;
    }

    void pop()
    {
        node *temp = list;
        if (list->data < min)
        {
            min = 2 * min - list->data;
        }
        list = list->next;
        delete temp;
    }

    int isEmpty()
    {
        return list == NULL;
    }

    int getMin()
    {
        return min;
    }
};

int main()
{
    LinkedStack stack;
    stack.push(10);
    cout << stack.getMin() << endl;
    stack.push(9);
    cout << stack.getMin() << endl;
    stack.push(4);
    cout << stack.getMin() << endl;
    stack.push(5);
    cout << stack.getMin() << endl;
}