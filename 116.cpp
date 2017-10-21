/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
        {
            return;
        }
        queue<TreeLinkNode*> q;
        int i=1;
        q.push(root);
        TreeLinkNode* tmp=NULL;
        while(!q.empty())
        {
            TreeLinkNode* p=q.front();
            q.pop();
            if(tmp!=NULL)
            {
                tmp->next=p;
            }
            tmp=p;
            if(fun(i))
            {
                tmp=NULL;
            }
            if(p->left!=NULL)
            {
                q.push(p->left);
                q.push(p->right);
            }
            i++;
        }
        return;
    }
private:
    bool fun(int i)
    {
        while(i)
        {
            if(i%2==0)
            {
                return false;
            }
            i/=2;
        }
        return true;
    }
};
