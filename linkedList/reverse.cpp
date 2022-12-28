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
ListNode *reverseList(ListNode *head);
int main()
{
    ListNode *head = NULL;
    inputlist(head, 4);
    inputlist(head, 3);
    inputlist(head, 8);
    inputlist(head, 9);
    inputlist(head, 1);
    printlist(head);

    head = reverseList(head);
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

ListNode *reverseList(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }
    ListNode *cur1, *cur2, *prev;
    cur2 = head;
    prev = head;
    cur1 = head;
    cur1 = head->next;
    prev->next = NULL;
    while (cur1 != NULL)
    {
        cur2 = cur1->next;
        cur1->next = prev;
        prev = cur1;
        cur1 = cur2;
    }
    return prev;
}