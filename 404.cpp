
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
    int sumOfLeftLeaves(TreeNode* root) {
        findleft(root,ans,0);
        return ans;
    }
private:
    int ans=0;
    void findleft(TreeNode *root,int &ans,int lr)
    {
        if(root==NULL)
        {
            return ;
        }
        else if(lr==1)
        {
            if(root->left==NULL&&root->right==NULL)
            {
                ans+=root->val;
                return;
            }
            if(root->left)
            {
                findleft(root->left,ans,1);
            }
            if(root->right)
            {
                findleft(root->right,ans,0);
            }
        }
        else if(lr==0)
        {
            if(root->left)
            {
                findleft(root->left,ans,1);
            }
            if(root->right)
            {
                findleft(root->right,ans,0);
            }
        }
        return;
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
    cout<<kk.sumOfLeftLeaves(Root)<<endl;
    return 0;
}

