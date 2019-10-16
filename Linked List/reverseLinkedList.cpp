#include <iostream>
#include <stddef.h>
#include <bits/stdc++.h>
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
        if (tail == NULL)
        {
            tail = head;
        }
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
        if (pos == 0)
        {
            this->insert_start(value);
        }
        else
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
    }

    //delete functions

    //delete first node
    void delete_first()
    {
        node *temp;
        temp = head;
        if (head != NULL)
            head = head->next;
        delete temp;
    }

    //delete last node
    void delete_last()
    {
        node *current = NULL;
        node *previous = NULL;
        current = head;
        if (head != NULL)
        {
            while (current->next != NULL)
            {
                previous = current;
                current = current->next;
            }
            tail = previous;
            delete current;
            if (tail != NULL)
                previous->next = NULL;
        }
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

    //reverse linked list iterative
    void reverse_iterative()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        node *prev = NULL;
        node *current = head;
        node *next = NULL;
        tail = head;
        while (current != NULL)
        {
            next = current->next; //store next
            current->next = prev; //change next to is prev node
            prev = current;       //update prev to current
            current = next;       //update currnet to next
        }
        head = prev;
    }

    void reverse_stack()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        stack<node *> s;
        s.push(NULL);
        node *temp = head;
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->next;
        }
        tail = head;
        head = s.top();
        while (s.top() != NULL)
        {
            temp = s.top();
            s.pop();
            temp->next = s.top();
        }
    }

    void reverse_recursive()
    {
        tail = head;
        this->reverse_recursive_helper(head);
        tail->next = NULL;
    }

    void reverse_recursive_helper(node *head1)
    {
        // cout << head1->data << " ";
        if (head1 == NULL)
        {
            return;
        }
        else
        {
            if (head1->next == NULL)
            {
                this->head = head1;
                return;
            }
            reverse_recursive_helper(head1->next);
            head1->next->next = head1;
            // cout << head1->data << endl;
        }
    }
};

int main()
{
    List list;
    //insert last
    list.insert_start(1);
    list.insert_last(2);
    list.insert_last(3);
    list.insert_last(4);
    list.insert_last(5);
    list.reverse_recursive();
    list.display();
    return 0;
}

//TODO: check null conditions on insert functions and also put some check conditions on insert and delete from given postion(1 position is not working).