#include<iostream>
#include<algorithm>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        visit(root,0);
        for(int i=0;i<ans.size();i++)
        {
            if(i%2==1)
            {
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
private:
    vector<vector<int>> ans;
    int visit(TreeNode* p,int n)
    {
        if(p==NULL)
        {
            return 0;
        }
        if(ans.size()==n)
        {
            vector<int> v;
            v.push_back(p->val);
            ans.push_back(v);
        }
        else
        {
            ans[n].push_back(p->val);
        }
        visit(p->left,n+1);
        visit(p->right,n+1);
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
    vector<vector<int>> V;
    V=kk.zigzagLevelOrder(Root);
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
