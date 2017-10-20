#include<iostream>
#include<vector>
using namespace std;

int a[1005];
int n;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int load(int i,TreeNode *r)
{
    if(2*i+1<n)
    {
        if(a[2*i+1]==0)
        {

        }
        else
        {
            TreeNode *p;
            p=new TreeNode(0);
            p->val=a[2*i+1];
            r->left=p;
            load(2*i+1,p);
        }
    }
    if(2*i+2<n)
    {
        if(a[2*i+2]==0)
        {

        }
        else
        {
            TreeNode *q;
            q=new TreeNode(0);
            q->val=a[2*i+2];
            r->right=q;
            load(2*i+2,q);
        }
    }
    return 0;
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==key)
        {
            if(!root->right)
            {
                TreeNode* left=root->left;
                root=left;
                return root;
            }
            else
            {
                TreeNode* right=root->right;
                while(right->left)
                {
                    right=right->left;
                }
                swap(root->val,right->val);
            }
        }
        root->left=deleteNode(root->left,key);
        root->right=deleteNode(root->right,key);
        return root;
    }
};

int pri(TreeNode* root)
{
    if(root==NULL)
    {
        cout<<"# ";
        return 0;
    }
    cout<<root->val<<" ";
    pri(root->left);
    pri(root->right);
    return 0;
}

int main()
{
    cout<<"please input the number of node:"<<endl;
    cin>>n;
    cout<<"please input the node you wanna delete:"<<endl;
    int key;
    cin>>key;
    cout<<"please input the node one by one(use zero to replace null):"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    TreeNode *Root;
    Root =new TreeNode(0);
    if(!n)
    {
        Root=NULL;
    }
    else
    {
        Root->val=a[0];
        load(0,Root);
    }
    Solution kk;
    Root=kk.deleteNode(Root,key);
    pri(Root);
    return 0;
}
