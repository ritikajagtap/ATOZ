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
ListNode *middleNode(ListNode *head);

int main()
{
    ListNode *head = NULL;
    inputlist(head, 4);
    inputlist(head, 3);
    inputlist(head, 8);
    inputlist(head, 9);
    inputlist(head, 1);
    printlist(head);
    ListNode* res = middleNode(head);
    cout<<"Middle Node: "<<res->val<<endl;
}
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;

    while (head && head->next)
    {
        slow = slow->next;
        head = head->next->next;
    }
    return slow;
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