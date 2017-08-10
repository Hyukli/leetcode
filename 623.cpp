#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int n;
int a[1005];

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
        {
            TreeNode* r=new TreeNode(v);
            r->left=root;
            return r;
        }
        ceng=d-1;
        visit(root,1,v);
        return root;
    }
private:
    int ceng;
    int visit(TreeNode* root,int n,int v)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(n==ceng)
        {
            TreeNode* l=new TreeNode(v);
            TreeNode* r=new TreeNode(v);
            l->left=root->left;
            r->right=root->right;
            root->left=l;
            root->right=r;
            return 0;
        }
        visit(root->left,n+1,v);
        visit(root->right,n+1,v);
        return 0;
    }
};

int dep(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(dep(root->left),dep(root->right))+1;
}

int dfs(vector<int> &v,TreeNode* root,int k,int n,int m)
{
    if(root==NULL)
    {
        return 0;
    }
    v[k]=root->val;
    dfs(v,root->left,k-pow(2,n),n-1,m+1);
    dfs(v,root->right,k+pow(2,n),n-1,m+1);
    return 0;
}

vector<int> pr(TreeNode *root)
{
    int d=dep(root);
    vector<int> v(pow(2,d)-1);
    for(int i=0;i<v.size();i++)
    {
        v[i]=0;
    }
    dfs(v,root,pow(2,d-1)-1,d-2,0);
    return v;
}

int main()
{
    int v,d;
    cout<<"please input the number of node:"<<endl;
    cin>>n;
    cout<<"please input the value you wanna add:"<<endl;
    cin>>v;
    cout<<"please input the depth of the row:"<<endl;
    cin>>d;
    cout<<"please input the node one by one(use zero to replace null):"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    TreeNode *Root,*root;
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
    root=kk.addOneRow(Root,v,d);
    vector<int> vv=pr(root);
    cout<<"ldr is: ";
    for(int i=0; i<vv.size(); i++)
    {
        cout<<vv[i]<<" ";
    }
    cout<<endl;
    return 0;
}
