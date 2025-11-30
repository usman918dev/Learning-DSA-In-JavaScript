#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <iostream>
using namespace std;

class Node
{
public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    };
    int getData()
    {
        return this->data;
    };
    void setNext(Node *next)
    {
        this->next = next;
    };
    Node *getNext()
    {
        return this->next;
    };

private:
    int data;
    Node *next;
};
class List
{
public:
    void add(int val)
    {
        Node *newnode = new Node(val);
        if (headnode == NULL)
        {
            cout << newnode->getData() << "one" << endl;
            headnode = newnode;
            currnode = headnode;
            lastcurrnode = NULL;
            size++;
        }
        else
        {
            cout << newnode->getData() << "two0" << endl;

            currnode->setNext(newnode);
            lastcurrnode = currnode;
            currnode = newnode;
            size++;
        }
        cout << newnode->getData() << "i<<" << endl;
    };
    void display()
    {
        Node *temp = headnode;
        int i = 0;
        while (temp != NULL)
        {

            cout << " ia am happy" << temp->getData() << i << endl;
            temp = temp->getNext();
            i++;
            if (i > 5)
                break;
        }
    };
    bool find(int val)
    {
        Node *temp = headnode;
        while (temp != NULL)
        {
            temp = temp->getNext();
            if (temp->getData() == val)
                return true;
        }
        return false;
    }
    void remove(int val)
    {
        if (headnode == NULL)
        {
            cout << "List is empty";
            return;
        }

        Node *curr = headnode;
        Node *prev = NULL;
        bool found = false;

        while (curr != NULL)
        {
            if (curr->getData() == val)
            {
                found = true;

                // If deleting head
                if (prev == NULL)
                {
                    headnode = curr->getNext();
                }
                else
                {
                    prev->setNext(curr->getNext());
                }

                delete curr;
                break;
            }

            prev = curr;
            curr = curr->getNext();
        }

        if (!found)
        {
            cout << "No element found";
        }
    }

private:
    Node *headnode = NULL;
    Node *currnode;
    Node *lastcurrnode;
    int size;
};
int main()
{
    List list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(40);
    list.add(40);
    // cout << "iamworking" << endl;
    list.display();
    cout << (list.find(30) == 1 ? "true" : "false") << endl;
    list.remove(20);
    list.display();
    getchar();
    return 0;
};