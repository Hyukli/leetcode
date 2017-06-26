#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int a[1005];
int b[1005];
int n,m;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int load1(int i,TreeNode *r)
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
            load1(2*i+1,p);
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
            load1(2*i+2,q);
        }
    }
    return 0;
}

int load2(int i,TreeNode *r)
{
    if(2*i+1<m)
    {
        if(b[2*i+1]==0)
        {

        }
        else
        {
            TreeNode *p;
            p=new TreeNode(0);
            p->val=b[2*i+1];
            r->left=p;
            load2(2*i+1,p);
        }
    }
    if(2*i+2<m)
    {
        if(b[2*i+2]==0)
        {

        }
        else
        {
            TreeNode *q;
            q=new TreeNode(0);
            q->val=b[2*i+2];
            r->right=q;
            load2(2*i+2,q);
        }
    }
    return 0;
}


class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t==NULL)
        {
            return true;
        }
        if(s==NULL)
        {
            return false;
        }
        if(s!=NULL&&t!=NULL)
        {
            if(s->val==t->val)
            {
                if(isSame(s,t))
                {
                    return true;
                }
            }
            return (isSubtree(s->left,t)||isSubtree(s->right,t));
        }
        return false;
    }
private:
    bool isSame(TreeNode* p,TreeNode *s)
    {
        if(p==NULL&&s==NULL)
        {
            return true;
        }
        if(p==NULL&&s!=NULL)
        {
            return false;
        }
        if(p!=NULL&&s==NULL)
        {
            return false;
        }
        if(p->val!=s->val)
        {
            return false;
        }
        if(!isSame(p->left,s->left)||!isSame(p->right,s->right))
        {
            return false;
        }
        return true;
    }
};

int main()
{
    cout<<"please input the number of the first tree`s node:"<<endl;
    cin>>n;
    cout<<"please input the node one by one(use zero to replace null):"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"please input the number of the second tree`s node:"<<endl;
    cin>>m;
    cout<<"please input the node one by one(use zero to replace null):"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    TreeNode *Root1,*Root2;
    Root1 =new TreeNode(0);
    Root2 =new TreeNode(0);
    if(!n)
    {
        Root1=NULL;
    }
    else
    {
        Root1->val=a[0];
        load1(0,Root1);
    }
    if(!m)
    {
        Root2=NULL;
    }
    else
    {
        Root2->val=b[0];
        load2(0,Root2);
    }
    Solution kk;
    cout<<(kk.isSubtree(Root1,Root2)?"Yes":"No")<<endl;
    return 0;
} 


