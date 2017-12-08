#include<iostream>
#include<vector>
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
    vector<TreeNode*> generateTrees(int n)
    {
        if(n==0)
        {
            vector<TreeNode*> v;
            return v;
        }
        return dfs(1,n);
    }
private:
    vector<TreeNode*> dfs(int start,int end)
    {
        if(start>end)
        {
            vector<TreeNode*> v;
            v.push_back(NULL);
            return v;
        }
        if(start==end)
        {
            vector<TreeNode*> v;
            TreeNode* node=new TreeNode(start);
            v.push_back(node);
            return v;
        }
        if(start<end)
        {
            vector<TreeNode*> ans;
            for(int i=start; i<=end; i++)
            {
                vector<TreeNode*> left=dfs(start,i-1);
                vector<TreeNode*> right=dfs(i+1,end);
                for(auto lnode:left)
                {
                    for(auto rnode:right)
                    {
                        TreeNode* root=new TreeNode(i);
                        root->left=lnode;
                        root->right=rnode;
                        ans.push_back(root);
                    }
                }
            }
            return ans;
        }
    }
};

int fp(TreeNode *i)
{
    if(i==NULL)
    {
        cout<<" ";
        return 0;
    }
    cout<<i->val;
    cout<<"#";
    fp(i->left);
    cout<<"#";
    fp(i->right);
    return 0;
}

int main()
{
    int n;
    Solution s;
    cin>>n;
    vector<TreeNode*> ans=s.generateTrees(n);
    for(int i=0;i<ans.size();i++)
    {
        fp(ans[i]);
        cout<<endl;
    }
    return 0;
}
