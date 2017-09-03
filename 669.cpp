#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val>=L&&root->val<=R)
        {
            root->left=trimBST(root->left,L,R);
            root->right=trimBST(root->right,L,R);
        }
        else if(root->val<L)
        {
            root=trimBST(root->right,L,R);
        }
        else
        {
            root=trimBST(root->left,L,R);
        }
        return root;
    }
};

int visit(TreeNode* root)
{
    if(root==NULL)
    {
        cout<<"# ";
        return 0;
    }
    cout<<root->val<<" ";
    visit(root->left);
    visit(root->right);
    return 0;
}

int main()
{
    cout<<"please input the number of node:"<<endl;
    cin>>n;
    cout<<"please input the node one by one(use zero to replace null):"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"please input the left and right:"<<endl;
    int l,r;
    cin>>l>>r;
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
    Root=kk.trimBST(Root,l,r);
    visit(Root);
    return 0;
}
