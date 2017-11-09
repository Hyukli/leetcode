#include<iostream>
#include<vector>
#include<map>
#include<math.h>
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        visit(root);
        return v;
    }
private:
    vector<TreeNode*> v;
    map<string,int> m;

    string itoa(int a)
    {
        int flag=0;
        if(a==0)
        {
            return "0";
        }
        if(a<0)
        {
            flag=1;
            a=-a;
        }
        string s="";
        while(a!=0)
        {
            int t=a%10;
            a/=10;
            char c=(t+'0');
            s=c+s;
        }
        if(flag)
        {
            string c="-";
            s=c+s;
        }
        return s;
    }

    string findstr(TreeNode *p)
    {
        if(p==NULL)
        {
            return " ";
        }
        string s=itoa(p->val);
        return s+"#"+findstr(p->left)+"#"+findstr(p->right);
    }

    int visit(TreeNode *p)
    {
        if(p==NULL)
        {
            return 0;
        }
        string s=findstr(p);
        if(m.find(s)!=m.end()&&m[s]==1)
        {
            v.push_back(p);
            m[s]++;
        }
        else
        {
            m[s]++;
        }
        visit(p->left);
        visit(p->right);
        return 0;
    }
};

int prt(TreeNode *p)
{
    if(p==NULL)
    {
        cout<<" ";
        return 0;
    }
    cout<<p->val;
    cout<<"#";
    prt(p->left);
    cout<<"#";
    prt(p->right);
    return 0;
}

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
    vector<TreeNode*> v=kk.findDuplicateSubtrees(Root);
    for(int i=0;i<v.size();i++)
    {
        prt(v[i]);
        cout<<endl;
    }
    return 0;
}

