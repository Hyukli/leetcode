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
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root,0);
        vector<double> D;
        for(int i=0;i<V.size();i++)
        {
            double sum=0;
            for(int j=0;j<V[i].size();j++)
            {
                sum+=V[i][j];
            }
            D.push_back(sum/V[i].size());
        }
        return D;
    }
private:
    vector<vector<int>> V;
    int dfs(TreeNode* root,int n)
    {
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            if(V.size()<=n)
            {
                vector<int> v;
                v.push_back(root->val);
                V.push_back(v);
            }
            else
            {
                V[n].push_back(root->val);
            }
            dfs(root->left,n+1);
            dfs(root->right,n+1);
            return 0;
        }
    }
};
