#include<iostream>
#include<vector>
using namespace std;

int a[1005];
int n;

struct TreeNode {
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
    int getMinimumDifference(TreeNode* root) {
        dfsTree(root);
        int min=100000000;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]-v[i-1]<min)
            {
                min=v[i]-v[i-1];
            }
        }
        return min;
    }
private:
    vector<int> v;
    int dfsTree(TreeNode* node)
        {
            if(node->left!=NULL)
            {
                dfsTree(node->left);
            }
            v.push_back(node->val);
            if(node->right!=NULL)
            {
                dfsTree(node->right);
            }
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
    cout<<kk.getMinimumDifference(Root)<<endl;
    return 0;
    return 0;
}
