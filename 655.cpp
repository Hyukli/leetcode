#include<map>
#include<iostream>
#include<sstream>
#include<string>
#include<math.h>
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
    vector<vector<string> > printTree(TreeNode* root) {
        int d=dep(root);
        for(int i=0;i<d;i++)
        {
            vector<string> v;
            for(int i=0;i<pow(2,d)-1;i++)
            {
                string s="";
                v.push_back(s);
            }
            V.push_back(v);
        }
        dfs(root,pow(2,d-1)-1,d-2,0);
        return V;
    }
private:
    vector<vector<string> > V;
    int dep(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return max(dep(root->left),dep(root->right))+1;
    }
    int dfs(TreeNode* root,int k,int n,int m)
    {
        if(root==NULL)
        {
            return 0;
        }
        string s;
        stringstream ss;
        ss<<root->val;
        ss>>s;
        V[m][k]=s;
        dfs(root->left,k-pow(2,n),n-1,m+1);
        dfs(root->right,k+pow(2,n),n-1,m+1);
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
    vector<vector<string> > V;
    V=kk.printTree(Root);
    for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            cout<<"\""<<V[i][j]<<"\" ";
        }
        cout<<endl;
    }
    return 0;
}


