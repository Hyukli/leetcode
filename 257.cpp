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
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,s);
        return v;
    }
private:
    vector<string> v;
    string s="";
    int dfs(TreeNode *root,string s)
    {
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            stringstream ss;
            string str;
            ss<<root->val;
            ss>>str;
            s+=str;
        }
        if(root->right==NULL&&root->left==NULL)
        {
            v.push_back(s);
        }
        else
        {
            s+="->";
            if(root->left)
            {
                dfs(root->left,s);
            }
            if(root->right)
            {
                dfs(root->right,s);
            }
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
    vector<string> v;
    v=kk.binaryTreePaths(Root);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}

