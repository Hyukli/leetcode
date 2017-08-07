#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if(nums.size()==0)
        {
            return NULL;
        }
        TreeNode* root=build(nums,0,nums.size()-1);
        return root;
    }
private:
    TreeNode* build(vector<int>& nums,int begin,int end)
    {
        if(begin>end)
        {
            return NULL;
        }
        int m=begin;
        for(int i=m; i<=end; i++)
        {
            if(nums[i]>nums[m])
            {
                m=i;
            }
        }
        TreeNode *t=new TreeNode(nums[m]);
        t->left=build(nums,begin,m-1);
        t->right=build(nums,m+1,end);
        return t;
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
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    TreeNode *root=s.constructMaximumBinaryTree(v);
    vector<int> vv=pr(root);
    for(int i=0; i<vv.size(); i++)
    {
        cout<<vv[i]<<" ";
    }
    cout<<endl;
    return 0;
}
