#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void inputlist(Node *&head, int x);
void printlist(Node *head);
void deleteAllOccurOfX(Node *&head_ref, int x);
int main()
{
    Node *head = NULL;
    inputlist(head, 4);
    inputlist(head, 3);
    inputlist(head, 3);
    inputlist(head, 3);
    inputlist(head, 3);
    inputlist(head, 3);
    inputlist(head, 8);
    inputlist(head, 9);
    inputlist(head, 1);
    printlist(head);
    deleteAllOccurOfX(head, 3);
    printlist(head);
}

void deleteAllOccurOfX(Node *&head_ref, int x)
{
    struct Node *cur = head_ref;
    struct Node *tmp = head_ref;
    if (head_ref == NULL)
    {
        return;
    }
    if (cur->next == NULL)
    {
        if (cur->data == x)
        {
            head_ref = NULL;
            delete (cur);
            return;
        }
        else
        {
            return;
        }
    }

    while (cur != NULL)
    {
        if (cur->data == x)
        {
            if (cur->prev == NULL)
            {
                cur->next->prev = NULL;

                tmp = cur->next;
                head_ref = tmp;
            }
            else if (cur->next == NULL)
            {
                cur->prev->next = NULL;
            }
            else
            {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
        }
        cur = cur->next;
    }
}

void inputlist(Node *&head, int x)
{ // we have taken head by reference and not by value coz we've to modify it here

    Node *temp;

    Node *newnode = new Node();
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}

void printlist(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "\n\t\t\t\tThe list is Empty" << endl;
    }
    else
    {

        while (temp->next)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}