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

class Solution
{
public:
    string tree2str(TreeNode* t)
    {
        string s="";
        if(t!=NULL)
        {
            stringstream ss;
            ss<<t->val;
            string v=ss.str();
            s+=v;
            if(t->left!=NULL)
            {
                s+='(';
                s+=tree2str(t->left);
                s+=')';
            }
            else if(t->left==NULL&&t->right!=NULL)
            {
                s+='(';
                s+=')';
            }
            if(t->right!=NULL)
            {
                s+='(';
                s+=tree2str(t->right);
                s+=')';
            }
        }
        return s;
    }
};

int main()
{
    cout<<"please input the number of node£º"<<endl;
    cin>>n;
    cout<<"please input the node one by one(use zero to replace null)£º"<<endl;
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
    cout<<kk.tree2str(Root)<<endl;
    return 0;
}
