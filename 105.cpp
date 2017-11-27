#include<iostream>
#include<vector>
using namespace std;

 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int fun(TreeNode* root)
{
    if(root==NULL)
    {
        cout<<"# ";
        return 0;
    }
    cout<<root->val<<" ";
    fun(root->left);
    fun(root->right);
    return 0;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0,0,inorder.size()-1,preorder,inorder);
    }
private:
    TreeNode* helper(int ps,int is,int ie,vector<int> pre,vector<int> in)
    {
        if(ps>pre.size()-1||is>ie)
        {
            return NULL;
        }
        int i;
        for(i=is;i<=ie;i++)
        {
            if(in[i]==pre[ps])
            {
                break;
            }
        }
        TreeNode *root=new TreeNode(pre[ps]);
        root->left=helper(ps+1,is,i-1,pre,in);
        root->right=helper(ps+i-is+1,i+1,ie,pre,in);
        return root;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<int> pr(n),in(n);
    for(int i=0;i<n;i++)
    {
        cin>>pr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    TreeNode* root=s.buildTree(pr,in);
    fun(root);
    return 0;
}
