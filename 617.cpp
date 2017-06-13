
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *t;
        t=new TreeNode(0);
        if(t1==NULL&&t2==NULL)
        {
            return NULL;
        }
        if(t1||t2)
        {
            if(t1&&t2)
            {
                t->val=t1->val+t2->val;
                t->left=mergeTrees(t1->left,t2->left);
                t->right=mergeTrees(t1->right,t2->right);
            }
            else if(t1==NULL)
            {
                t->val=t2->val;
                t->left=mergeTrees(t1,t2->left);
                t->right=mergeTrees(t1,t2->right);
            }
            else if(t2==NULL)
            {
                t->val=t1->val;
                t->left=mergeTrees(t1->left,t2);
                t->right=mergeTrees(t1->right,t2);
            }
        }
        return t;
    }
};
