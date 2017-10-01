#include<iostream>
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
    int longestUnivaluePath(TreeNode* root) {
        visit(root);
        return ans;
    }
private:
    int ans=0;
    int findl(TreeNode* root,int k,int c)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(k!=root->val)
        {
            return 0;
        }
        if(c==1)
        {
            return 1+findl(root->left,k,2)+findl(root->right,k,2);
        }
        return 1+max(findl(root->left,k,2),findl(root->right,k,2));
    }
    int visit(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int k=findl(root,root->val,1)-1;
        if(k>ans)
        {
            ans=k;
        }
        visit(root->left);
        visit(root->right);
        return 0;
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
    cout<<kk.longestUnivaluePath(Root)<<endl;
    return 0;
}
