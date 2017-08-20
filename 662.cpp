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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        visit(root,1,1);
        int ans=1;
        for(int i=0;i<V.size();i++)
        {
            ans=max(ans,V[i][V[i].size()-1]-V[i][0]+1);
        }
        return ans;
    }
private:
    vector<vector<int>> V;
    int visit(TreeNode* root,int dep,int num)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(V.size()<dep)
        {
            vector<int> v;
            v.push_back(num);
            V.push_back(v);
        }
        else
        {
            V[dep-1].push_back(num);
        }
        visit(root->left,dep+1,num*2);
        visit(root->right,dep+1,num*2+1);
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
    cout<<kk.widthOfBinaryTree(Root)<<endl;;
    return 0;
}
