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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
        {
            return ans;
        }
        vector<int> v;
        dfs(sum,0,v,root);
        return ans;
    }
private:
    vector<vector<int>> ans;
    int dfs(int sum,int tmp,vector<int> v,TreeNode* root)
    {
        v.push_back(root->val);
        tmp+=root->val;
        if(root->left==NULL&&root->right==NULL)
        {
            if(tmp==sum)
            {
                ans.push_back(v);
                return 0;
            }
        }
        if(root->left!=NULL)
        {
            dfs(sum,tmp,v,root->left);
        }
        if(root->right!=NULL)
        {
            dfs(sum,tmp,v,root->right);
        }
        return 0;
    }
};

int main()
{
    cout<<"please input the number of node:"<<endl;
    cin>>n;
    cout<<"please input the path sum:"<<endl;
    int sum;
    cin>>sum;
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
    vector<vector<int>> V=kk.pathSum(Root,sum);
    for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
