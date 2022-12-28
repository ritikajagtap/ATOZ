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
ListNode *deleteMiddle(ListNode *head);

int main()
{
    ListNode *head = NULL;
    inputlist(head, 4);
    inputlist(head, 3);
    inputlist(head, 8);
    inputlist(head, 9);
    inputlist(head, 1);
    printlist(head);
    head = deleteMiddle(head);
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

ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        head = NULL;
        return head;
    }
    if (head->next->next == NULL)
    {
        if (head->next->next == NULL)
        {
            head->next = NULL;
            delete (head->next);
        }
        return head;
    }

    ListNode *slow, *fast;
    slow = head;
    fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow->next)
    {
        slow->val = slow->next->val;
        slow->next = slow->next->next;
    }

    return head;
}