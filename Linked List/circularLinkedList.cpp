#include <iostream>
#include <stddef.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class List
{
private:
    node *tail;

public:
    List()
    {
        tail = NULL;
    }

    //print the list
    void display()
    {
        node *temp = tail->next;
        while (temp->next != tail)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << temp->data << "\t";
    }

    //insert functions

    //insert at begining
    void insert_start(int value)
    {
        node *temp = new node;
        temp->data = value;
        if (tail != NULL)
        {
            temp->next = tail->next;
            tail->next = temp;
            temp->prev = tail;
        }
        else
        {
            tail = temp;
            tail->next = tail;
            tail->prev = tail;
        }
    }

    //insert at last
    void insert_last(int value)
    {
        node *temp = new node;
        if (tail == NULL)
        {
            this->insert_start(value);
        }
        else
        {
            temp->data = value;
            temp->next = tail->next;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }

        // temp->next = NULL;
        // if (head == NULL)
        // {
        //     head = temp;
        //     temp->prev = NULL;
        //     tail = temp;
        // }
        // else
        // {
        //     tail->next = temp;
        //     temp->prev = tail;
        //     tail = temp;
        // }
    }

    //insert node at a position i
    void insert_position(int pos, int value)
    {
        cout << "insert_position" << endl;
        if (pos == 0)
        {
            this->insert_start(value);
        }
        else
        {
            node *pre = NULL;
            node *cur = NULL;
            node *temp = new node;
            cur = tail->next;
            for (int i = 1; i < pos; i++)
            {
                pre = cur;
                cur = cur->next;
            }
            temp->data = value;
            pre->next = temp;
            temp->prev = pre;
            temp->next = cur;
        }
    }

    //delete functions

    //delete first node
    void delete_first()
    {
        node *temp;
        temp = tail->next;
        if (tail->next != NULL)
            tail->next = tail->next->next;
        delete temp;
    }

    //delete last node
    void delete_last()
    {
        node *temp = tail;
        tail->next->prev = tail->prev;
        tail->prev->next = tail->next;
        tail = tail->prev;
        delete temp;
    }

    //delete at position i
    void delete_position(int pos)
    {
        node *current = NULL;
        node *previous = NULL;
        current = tail->next;
        for (int i = 1; i < pos; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        current->next->prev = previous;
        delete current;
    }
};

int main()
{

    List list;
    //insert last
    list.insert_start(1);
    list.insert_last(2);
    cout << "insert last" << endl;
    list.display();
    cout << endl
         << endl;

    //insert start
    list.insert_start(0);
    cout << "insert start" << endl;
    list.display();
    cout << endl
         << endl;

    //insert index i
    list.insert_position(2, 5);
    cout << "insert at position 2" << endl;
    list.display();
    cout << endl
         << endl;

    //delete from end
    list.delete_last();
    cout << "delete last" << endl;
    list.display();
    cout << endl
         << endl;

    //delete first
    list.delete_first();
    cout << "delete first" << endl;
    list.display();
    cout << endl
         << endl;

    //TODO:debug this method.
    //insert start
    // list.delete_position(2);
    // cout << "delete postion 2" << endl;
    // list.display();
    // cout << endl
    //      << endl;

    return 0;
}

//TODO: check null conditions on insert functions and also put some check conditions on insert and delete from given postion(1 position is not working).