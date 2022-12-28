#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
};

void inputlist(ListNode *&head, int x);
void printlist(ListNode *head);
ListNode *removeNthFromEnd(ListNode *head, int n);

int main()
{
    ListNode *head = NULL;
    inputlist(head, 4);
    inputlist(head, 3);
    inputlist(head, 8);
    inputlist(head, 9);
    inputlist(head, 1);
    printlist(head);
    head = removeNthFromEnd(head, 2);
    printlist(head);

}

void inputlist(ListNode *&head, int x)
{ // we have taken head by reference and not by value coz we've to modify it here
    
    ListNode *temp;

    ListNode *newnode = new ListNode();
    newnode->val = x;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void printlist(ListNode *head)
{
    ListNode *temp = head;
    if (head == NULL)
    {
        cout << "\n\t\t\t\tThe list is Empty" << endl;
    }
    else
    {

        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}
ListNode *removeNthFromEnd(ListNode *head, int n)
{

    ListNode *temp1 = head;
    ListNode *temp2 = head;
    int i = 0;

    while (i < n)
    {
        temp1 = temp1->next;
        i++;
    }
    if (temp1 == NULL)
    {
        return head->next;
    }
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp2->next = temp2->next->next;
    return head;
}