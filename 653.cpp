#include<map>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int a[1005];
int n,value;

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
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
        {
            return false;
        }
        visit(root);
        for(auto mm:m)
        {
            if(mm.first*2==k)
            {
                if(mm.second>=2)
                {
                    return true;
                }
            }
            else if(m.find(k-mm.first)!=m.end())
            {
                return true;
            }
        }
        return false;
    }
private:
    map<int,int> m;
    int visit(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(m.find(root->val)!=m.end())
        {
            m[root->val]++;
        }
        else
        {
            m[root->val]=1;
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
    cout<<"please input the value:"<<endl;
    cin>>value;
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
    cout<<(kk.findTarget(Root,value)?"Yes":"No")<<endl;
    return 0;
}

