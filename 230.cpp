
#include<iostream>
using namespace std;

int a[1005];
int n,sum;

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
    int kthSmallest(TreeNode* root, int k) {
        if(findl(root)==k-1)
        {
            return root->val;
        }
        else if(findl(root)>k-1)
        {
            return kthSmallest(root->left,k);
        }
        else
        {
            return kthSmallest(root->right,k-findl(root)-1);
        }
    }
private:
    int finda(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            int ans=0;
            if(root->left!=NULL)
            {
                ans+=(1+finda(root->left));
            }
            if(root->right!=NULL)
            {
                ans+=(1+finda(root->right));
            }
            return ans;
        }
    }
    int findl(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            int ans=0;
            if(root->left!=NULL)
            {
                ans+=(1+finda(root->left));
            }
            return ans;
        }
    }
};

int main()
{
    int k;
    cout<<"please input the number of node and the kth num you wanna find:"<<endl;
    cin>>n>>k;
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
    cout<<kk.kthSmallest(Root,k)<<endl;
    return 0;
}
