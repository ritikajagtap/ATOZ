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
void createCycle(ListNode* &head,int a,int b); 
bool hasCycle(ListNode *head);
int main()
{
    ListNode *head = NULL;
    inputlist(head, 4);
    inputlist(head, 3);
    inputlist(head, 8);
    inputlist(head, 9);
    inputlist(head, 1);
    createCycle(head, 1, 3);
    cout<<hasCycle(head);
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

void createCycle(ListNode* &head,int a,int b) 
{
    int cnta = 0,cntb = 0;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while(cnta != a || cntb != b) {
        if(cnta != a) p1 = p1->next, ++cnta;
        if(cntb != b) p2 = p2->next, ++cntb;
    }
    p2->next = p1;
}


bool hasCycle(ListNode *head)
{

    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    ListNode *fast, *slow;
    fast = head;
    slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {

        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}