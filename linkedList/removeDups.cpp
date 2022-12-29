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
void removeDuplicates( Node *head);
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
    removeDuplicates(head);
    printlist(head);
}

void removeDuplicates( Node *head)
    {
        Node* cur1 = head;
        Node* cur2 = head;
        if(cur1->next == NULL)
        {
            return;
        }
        while(cur2)
        {
            if(cur1->data != cur2->data){
                cur1->next = cur2;
                cur2->prev = cur1;
                
                cur1 = cur2;
            }
            cur2 = cur2->next;
        }
        cur1->next = NULL;
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