#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *bottom;
};

void inputlist(Node *&head, int n, int b);
void printlist(Node *head);
Node *flatten(Node *root);
Node *merge(Node *a, Node *b);

int main()
{
    Node *head = NULL;

    inputlist(head, 5, 0);
    inputlist(head, 7, 1);
    inputlist(head, 8, 1);
    inputlist(head, 30, 1);
    inputlist(head, 10, 0);
    inputlist(head, 20, 1);
    inputlist(head, 19, 0);
    inputlist(head, 22, 1);
    inputlist(head, 50, 1);
    inputlist(head, 28, 0);
    inputlist(head, 35, 1);
    inputlist(head, 40, 1);
    inputlist(head, 45, 1);
    cout<<"input list: ";
    printlist(head);
    cout<<"output list: ";
    head = flatten(head);
    printlist(head);
}
Node *merge(Node *a, Node *b)
{
    Node* tmp = new Node();
    Node* res = tmp;
    
    while(a!=NULL && b!=NULL)
    {
        tmp->next = NULL;
        if(a->data<b->data)
        {
            tmp->bottom = a;
            tmp = tmp->bottom;
            a = a->bottom;
        }else{
            tmp->bottom = b;
            tmp= tmp->bottom;
            b = b->bottom;
        }
    }
        tmp->next=NULL;
    if(a){
        tmp->bottom = a;
    }else{
        tmp->bottom = b;
    }
    return res->bottom;
}
Node *flatten(Node *root)
{
    if(!root || !root->next)
   {
       return root;
   }
   root->next = flatten(root->next);
   
   root = merge(root, root->next);
   
   return root;
   
}
void inputlist(Node *&head, int n, int b)
{ // we have taken head by reference and not by dataue coz we've to modify it here
    
    Node *temp = head;

    Node *newnode = new Node();
     newnode->data = n;
    newnode->next = NULL;
    newnode->bottom = NULL;

    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        if(b == 0)
        {
            while(temp->next)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }else{
            while(temp->next)
            {
                temp = temp->next;
            }
            while(temp->bottom){
                temp= temp->bottom;
            }
            temp->bottom = newnode;
            temp->next = NULL;
        }
        
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
        Node *temp2 = head;
        while (temp)
        {
            temp2 = temp;
            while(temp2)
            {
                cout<<temp2->data<<" ";
                temp2 = temp2->bottom;
            }
            temp = temp->next;
        }
    }
    cout << endl;
}