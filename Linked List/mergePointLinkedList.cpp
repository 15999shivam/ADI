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
        cout << endl;
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
                cout << "Found Loop";
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
};

int main()
{
    List list1;
    //insert last
    list1.insert_start(1);
    list1.insert_last(2);
    list1.insert_last(3);
    list1.insert_last(4);
    list1.insert_last(5);
    list1.insert_last(6);

    List list2;
    list2.insert_start(8);
    list2.insert_last(9);

    //make merge

    node *head1 = list1.getHead();
    node *tail1 = list1.getTail();

    node *head2 = list2.getHead();
    node *tail2 = list2.getTail();

    int i = 2;
    while (i--)
    {
        head1 = head1->next;
    }
    tail2->next = head1;

    //reinitialise head and tails
    head1 = list1.getHead();
    tail2 = tail1;
    head2 = head2; // not necessary
    tail1 = tail1; //not necessary

    tail1->next = head1; //make loop in first linked list

    node *slow = head2;
    node *fast = head2;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }

    slow = head2;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    cout << slow->data << endl;

    //restore the previous state if lists
    tail1->next = NULL;
    list2.display();
    list1.display();

    //display lists
    // list1.display();
    // list2.display();

    return 0;
}

//TODO: check null conditions on insert functions and also put some check conditions on insert and delete from given postion(1 position is not working).