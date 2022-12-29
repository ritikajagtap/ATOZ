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
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target);

int main()
{
    Node *head = NULL;
    inputlist(head, 4);
    inputlist(head, 3);
    inputlist(head, 2);
    inputlist(head, 8);
    inputlist(head, 9);
    inputlist(head, 1);
    printlist(head);
    vector<pair<int, int>> res = findPairsWithGivenSum(head, 5);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<"(";
        cout << res[i].first;
        cout<<",";
        cout << res[i].second;
        cout<<") ";
        
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

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{

    set<int> mp;
    vector<pair<int, int>> res;
    Node *cur = head;
    while (cur)
    {
        pair<int, int> tmp;
        tmp.first = -1;
        tmp.second = -1;
        if (mp.find(target - cur->data) != mp.end())
        {
            tmp.first = abs(cur->data - target);
            tmp.second = cur->data;
        }
        else
        {
            mp.insert(cur->data);
        }
        if (tmp.first != -1)
        {
            res.push_back(tmp);
        }
        cur = cur->next;
    }
    sort(res.begin(), res.end());

    return res;
}