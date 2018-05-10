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
        TreeNode *p;
        p=new TreeNode(0);
        p->val=a[2*i+1];
        r->left=p;
        load(2*i+1,p);
    }
    if(2*i+2<n)
    {
        TreeNode *q;
        q=new TreeNode(0);
        q->val=a[2*i+2];
        r->right=q;
        load(2*i+2,q);
    }
    return 0;
}

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

class Solution
{
public:
    TreeNode* pruneTree(TreeNode* root)
    {
        if(!have1(root))
        {
            root=NULL;
            return root;
        }
        else
        {
            root->left=pruneTree(root->left);
            root->right=pruneTree(root->right);
        }
        return root;
    }
private:
    bool have1(TreeNode* root)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->val==1)
        {
            return true;
        }
        return (have1(root->left)||have1(root->right));
    }
};

int main()
{
    cout<<"please input the number of node:"<<endl;
    cin>>n;
    cout<<"please input the node one by one:"<<endl;
    for(int i=0; i<n; i++)
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
    Root=kk.pruneTree(Root);
    visit(Root);
    return 0;
}
