#include <iostream>
using namespace std;

struct node
{
    char data;
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

    void push(char n)
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

    char peek()
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

int bracketsValidation(string s)
{
    LinkedStack stack;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            stack.push(s[i]);
        }
        else
        {
            if (s[i] == ')')
            {
                if ( !stack.isEmpty() &&  stack.peek() == '(')
                {
                    stack.pop();
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    if (stack.isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cout << bracketsValidation("(one (two (three (four (five six (seven (eight (nine (ten ))))))))))");
    cout << bracketsValidation("((((((((((a))))))))))");
    return 0;
}