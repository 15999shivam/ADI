#include <iostream>
using namespace std;

struct node
{
    string data;
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

    void push(string n)
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

    string peek()
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

int HtmlTagValidator(string s)
{
    cout << s << endl;
    LinkedStack stack;
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '<' && s[i + 1] != '/')
        {
            i++;
            temp = "";
            while (s[i] != '>' && s[i] != '\0')
            {
                temp = temp + s[i];
                // cout << temp << endl;
                i++;
            }
            cout << "making " << temp << endl;
            stack.push(temp);
        }
        else
        {
            if (s[i] == '<' && s[i + 1] == '/')
            {
                i++;
                i++;
                temp = "";
                while (s[i] != '>' && s[i] != '\0')
                {
                    temp = temp + s[i];
                    i++;
                }
                cout << "popping " << temp << endl;
                if (!stack.isEmpty() && temp == stack.peek())
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
    if (!stack.isEmpty())
    {
        return 0;
    }
    return 1;
}

int main()
{
    // LinkedStack stack;
    // stack.push("yo babay");
    // cout << stack.peek() << endl;
    cout << HtmlTagValidator("<html><h1>hi</h></html>");
    return 0;
}