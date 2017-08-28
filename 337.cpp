#include<iostream>
#include<map>
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
    int rob(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        if(m.find(root)!=m.end())
        {
            return m[root];
        }
        int val=0;
        if(root->left)
        {
            val+=(rob(root->left->left)+rob(root->left->right));
        }
        if(root->right)
        {
            val+=(rob(root->right->left)+rob(root->right->right));
        }
        return m[root]=max(val+root->val,rob(root->left)+rob(root->right));
    }
private:
    map<TreeNode*,int> m;
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
    cout<<kk.rob(Root)<<endl;
    return 0;
}
