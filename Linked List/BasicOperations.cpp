#include <iostream>
#include <stddef.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

class List
{
private:
    node *head, *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    //print the list
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }

    //insert functions

    //insert at begining
    void insert_start(int value)
    {
        node *temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    //insert at last
    void insert_last(int value)
    {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    //insert node at a position i
    void insert_position(int pos, int value)
    {
        node *pre = new node;
        node *cur = new node;
        node *temp = new node;
        cur = head;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        temp->data = value;
        pre->next = temp;
        temp->next = cur;
    }

    //delete functions

    //delete first node
    void delete_first()
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }

    //delete last node
    void delete_last()
    {
        node *current;
        node *previous = new node;
        current = head;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous->next = NULL;
        delete current;
    }

    //delete at position i
    void delete_position(int pos)
    {
        node *current = new node;
        node *previous = new node;
        current = head;
        for (int i = 1; i < pos; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
    }
};

int main()
{
    List list;
    //insert last
    list.insert_last(1);
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

    //insert start
    list.delete_position(2);
    cout << "delete postion 2" << endl;
    list.display();
    cout << endl
         << endl;

    return 0;
}

//TODO: check null conditions on insert functions and also put some check conditions on insert and delete from given postion(1 position is not working).