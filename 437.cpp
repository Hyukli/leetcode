#include<iostream>
#include<sstream>
#include<string>
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
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
        {
            return 0;
        }
        dfs(root,0,sum);
        if(root->left)
        {
            pathSum(root->left,sum);
        }
        if(root->right)
        {
            pathSum(root->right,sum);
        }
        return ans;
    }
private:
    int ans=0;
    int dfs(TreeNode *p,int tsum,int sum)
    {
        tsum+=p->val;
        if(tsum==sum)
        {
            ans++;
        }
        if(p->left)
        {
            dfs(p->left,tsum,sum);
        }
        if(p->right)
        {
            dfs(p->right,tsum,sum);
        }
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
    cout<<"please input the sum:"<<endl;
    cin>>sum;
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
    cout<<kk.pathSum(Root,sum)<<endl;
    return 0;
}

