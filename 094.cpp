#include<iostream>
#include<sstream>
#include<string>
#include<stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        dlr(root);
        return v;
    }
private:
    vector<int> v;
    int dlr(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        dlr(root->left);
        v.push_back(root->val);
        dlr(root->right);
        return 0;
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode *p=root;
        while(!s.empty()||p)
        {
            if(p)
            {
                s.push(p);
                p=p->left;
            }
            else
            {
                TreeNode *n=s.top();
                ans.push_back(n->val);
                s.pop();
                p=n->right;
            }
        }
        return ans;
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
    Solution2 kk;
    vector<int> V;
    V=kk.inorderTraversal(Root);
    for(int i=0;i<V.size();i++)
    {
        cout<<V[i]<<" ";
    }
    cout<<endl;
    return 0;
}
