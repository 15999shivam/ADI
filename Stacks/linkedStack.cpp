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
            list->next = NULL;
        }
        else
        {
            temp->next = list;
            list = temp;
        }
    }

    int peek()
    {
        return list->data;
    }

    void pop()
    {
        node *temp = list;
        list = list->next;
        delete temp;
    }

    int isEmpty()
    {
        return list == NULL;
    }
};

int main()
{
    LinkedStack stack;
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