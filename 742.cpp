#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

int a[1005];
int n,k;

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
    int findClosestLeaf(TreeNode* root, int k) {
        vector<int> v;
        findleaf(v,root,k);
        int ans=0;
        int minw=90000000;
        for(int i=0;i<lp.size();i++)
        {
            int j;
            for(j=0;j<t.size()&&j<lp[i].size();j++)
            {
                if(lp[i][j]!=t[j])
                {
                    break;
                }
            }
            int s=t.size()+lp[i].size()-2*j;
            if(s<minw)
            {
                minw=s;
                ans=lp[i][lp[i].size()-1];
            }
        }
        return ans;
    }
private:
    vector<vector<int>> lp;
    vector<int> t;
    int findleaf(vector<int> v,TreeNode* root,int k)
    {
        if(root->val==k)
        {
            v.push_back(k);
            t=v;
            v.pop_back();
        }
        v.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            lp.push_back(v);
        }
        if(root->left)
        {
            findleaf(v,root->left,k);
        }
        if(root->right)
        {
            findleaf(v,root->right,k);
        }
        return 0;
    }
};

int main()
{
    cout<<"please input the number of node and target k:"<<endl;
    cin>>n>>k;
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
    cout<<kk.findClosestLeaf(Root,k)<<endl;
    return 0;
}
