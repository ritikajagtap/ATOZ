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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
int main()
{
    ListNode *head = NULL;
    inputlist(head, 4);
    inputlist(head, 3);
    inputlist(head, 8);
    inputlist(head, 9);
    inputlist(head, 1);
    ListNode* head2 = NULL;
    inputlist(head2, 4);
    inputlist(head2, 6);
    inputlist(head2, 2);
    ListNode* head3 = NULL;
    inputlist(head3, 33);
    inputlist(head3, 32);
    inputlist(head3, 31);

    head->next->next->next->next->next = head3;
    head2->next->next->next = head3;
    printlist(head);
    printlist(head2);
    
    ListNode* inter = getIntersectionNode(head, head2);
    cout<<inter->val<<endl;
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

int diff1(ListNode *headA, ListNode *headB)
{

    int cnt1 = 0;
    int cnt2 = 0;
    while (headA)
    {
        headA = headA->next;
        cnt1++;
    }
    while (headB)
    {
        headB = headB->next;
        cnt2++;
    }

    return cnt1 - cnt2;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL && headB == NULL)
    {
        return headA;
    }

    int diff = diff1(headA, headB);
    if (diff < 0)
    {
        while (diff != 0 && headB)
        {
            diff++;
            headB = headB->next;
        }
    }
    else
    {
        while (diff != 0 && headA)
        {
            diff--;
            headA = headA->next;
        }
    }
    while (headA && headB)
    {
        if (headA == headB)
        {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}