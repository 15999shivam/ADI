#include <iostream>
using namespace std;

struct node
{
    string data;
    node *next;
};

class Hash
{

    node **arr;
    int size;

public:
    Hash(int size)
    {
        arr = new node *[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = NULL;
        }
        this->size = size;
    }

    //pushes data to hash
    void push(string s)
    {
        int temp = this->calHash(s);

        node *h = arr[temp];
        if (h == NULL)
        {
            node *nmi = new node;
            nmi->data = s;
            nmi->next = NULL;
            arr[temp] = nmi;
        }
        else
        {
            while (h->next != NULL)
            {
                if (h->data == s)
                {
                    break;
                }
                h = h->next;
            }
            if (h->data == s)
            {
                return;
            }
            node *nmi = new node;
            nmi->data = s;
            nmi->next = NULL;
            h->next = nmi;
        }
    }

    //print hash
    void printHash()
    {
        for (int i = 0; i < size; i++)
        {
            node *temp = arr[i];
            cout << i << " -> ";
            while (temp != NULL)
            {
                cout << temp->data << ", ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int calHash(string s)
    {
        int temp = 0;
        for (int i = 0; i < s.length(); i++)
        {
            temp = temp + s[i];
        }
        cout << endl
             << s << " " << temp << endl;
        return temp % size;
    }

    int find(string s)
    {
        int temp = this->calHash(s);
        node *h = arr[temp];

        while (h != NULL)
        {
            if (h->data == s)
            {
                return 1;
            }
            h = h->next;
        }
        return 0;
    }

    void pushString(string s)
    {
        string temp;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                this->push(temp);
                temp = "";
            }
            else
            {
                temp += s[i];
            }
        }
        this->push(temp);
    }
    int countWords()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            node *temp = arr[i];

            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
        }
        return count;
    }
};

int main()
{
    string s = "hello this is is test of hash hash function";

    Hash h(7);

    h.pushString(s);

    h.printHash();

    cout << h.find("hash") << endl;

    cout << "No. of Distinct words: " << h.countWords() << endl;
    return 0;
}
