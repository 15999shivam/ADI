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

    //get head
    node *getHead()
    {
        return head;
    }

    //get tail
    node *getTail()
    {
        return tail;
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

    //find middle method
    int middle()
    {
        node *slow = head;
        node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    //detect loop 0->fasle 1->true
    int isLoop()
    {
        node *slow = head;
        node *fast = head;

        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cout << "Found Loop" << endl;
                return 1;
                // break;
            }
        }

        //code for finding the start of the loop
        // slow = head;
        // while (slow != fast)
        // {
        //     slow = slow->next;
        //     fast = fast->next;
        // }
        // cout << "hii";
        // cout << slow->data << endl;
        return 0;
    }

    //remove loop in liked list
    void removeLoop()
    {
        node *slow = head;
        node *fast = head;
        int flag = 0;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cout << "Found Loop" << endl;
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            // code for finding the start of the loop
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            while (slow->next != fast)
            {
                slow = slow->next;
            }
            slow->next = NULL;
        };
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
    list.insert_last(6);

    //make loop
    node *head = list.getHead();
    node *tail = list.getTail();

    int i = 2;
    while (i--)
    {
        head = head->next;
    }
    tail->next = head;

    //detect loop
    cout << list.isLoop() << endl;
    // list.display(); //infinite print
    list.removeLoop();
    list.display(); //loop removed should print now

    return 0;
}

//TODO: check null conditions on insert functions and also put some check conditions on insert and delete from given postion(1 position is not working).