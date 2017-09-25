/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        visit(root,0);
        vector<int> ans;
        for(int i=0;i<V.size();i++)
        {
            ans.push_back(V[i][V[i].size()-1]);
        }
        return ans;
    }
private:
    vector<vector<int> > V;
    int visit(TreeNode *root,int n)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(V.size()==n)
        {
            vector<int> v;
            v.push_back(root->val);
            V.push_back(v);
        }
        else
        {
            V[n].push_back(root->val);
        }
        visit(root->left,n+1);
        visit(root->right,n+1);
        return 0;
    }
};
