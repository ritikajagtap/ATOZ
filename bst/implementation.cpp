#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
};

Node *newnode(int val)
{
    Node *temp = new Node();
    temp->left = NULL;
    temp->right = NULL;
    temp->val = val;
    return temp;
}

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = newnode(val);
        return root;
    }
    Node *node = root;
    while (node->left != NULL || node->right != NULL)
    {
        if (node->val < val)
        {
            if (node->right)
            {
                node = node->right;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (node->left)
            {
                node = node->left;
            }
            else
            {
                break;
            }
        }
    }
    if (node->val >= val)
    {
        node->left = newnode(val);
        // cout<<node->left->val<<" ";
    }
    else
    {
        node->right = newnode(val);
        // cout<<node->right->val<<" ";
    }
    return root;
}
Node* findLastRight(Node* root){
    if(root->right == NULL){return root;}
    return findLastRight(root->right);
}
Node* helper(Node* root){
    if(root->left == NULL){
        return root->right;
    }else if(root->right==NULL){
        return root->left;
    }
    else{
        // right child
        Node* rightChild = root->right;
        //  finding last right child of left subtree to attach right child of the root
        Node* lastRight = findLastRight(root);
        lastRight->right = rightChild;
        return root->left;
    }
}


Node* del(Node* root, int val){

    if(root ==NULL){
        return root;
    }
    if(root->val == val){
        return helper(root);
    }
    Node* dummy = root;
    while(root!=NULL){
        if(root->val>val){
            if(root->left!=NULL && root->left->val==val){
                root->left = helper(root->left);
            }else{
                root = root->left;
            }
        }else{
            if(root->right!=NULL && root->right->val==val){
                root->right = helper(root->right);
            }else{
                root = root->right;
            }
        }
    }
    return dummy;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->val << " ";
}

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    vector<int> ans;
    q.push(root);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        ans.push_back(cur->val);
        cout << cur->val << " ";
        if (cur->left)
        {
            q.push(cur->left);
        }
        if (cur->right)
        {
            q.push(cur->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 34);
    root = insert(root, 4);
    root = insert(root, 334);
    root = insert(root, 341);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    root = del(root, 334);
    preorder(root);
    cout<<endl;
    
}