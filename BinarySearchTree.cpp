#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

};
node* getnewnode(int d)
{
    node* newnode=new node();
    newnode->data=d;
    newnode->left=newnode->right=NULL;
    return newnode;
}
node* insert_ele(int data,node* root)
{
    if(root==NULL)
    {
        root=getnewnode(data);
    }
    else if(data <= root->data)
    {
        root->left=insert_ele(data,root->left);
    }
    else
    {
        root->right=insert_ele(data,root->right);
    }
    return root;
}
bool searchele(int d,node* root)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==d)
    {
        return true;
    }
    else if(d <= root->data)
    {
        return searchele(d,root->left);
    }
    else
    {
        return searchele(d,root->right);
    }
}

int main()
{
    int n;
    node* root=NULL;
    root=insert_ele(15,root);
    root=insert_ele(9,root);
    root=insert_ele(20,root);
    root=insert_ele(52,root);
    root=insert_ele(3,root);
    root=insert_ele(17,root);

    cout<<"Enter element to search\n.";
    cin>>n;
    searchele(n,root)==true?cout<<"Element found":cout<<"Element not found";

    return 0;
}
