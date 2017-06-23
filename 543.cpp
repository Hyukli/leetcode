#include<iostream>
#include<sstream>
#include<string>
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        if(dep(root->right)+dep(root->left)>ans)
        {
            ans=dep(root->right)+dep(root->left);
        }
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return ans;
    }
private:
    int ans=0;
    int dep(TreeNode* p)
    {
        if(p==NULL)
        {
            return 0;
        }
        if(p->left==NULL&&p->right==NULL)
        {
            return 1;
        }
        return 1+max(dep(p->left),dep(p->right));
    }
};

int main()
{
    cout<<"please input the number of node:"<<endl;
    cin>>n;
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
    cout<<kk.diameterOfBinaryTree(Root)<<endl;
    return 0;
}


