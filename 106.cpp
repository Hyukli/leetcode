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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,postorder.size()-1,0,inorder.size()-1);
    }
private:
    TreeNode *helper(vector<int>& inorder, vector<int>& postorder,int pe,int is,int ie)
    {
        if(pe<0||ie<is)
        {
            return NULL;
        }
        TreeNode *root=new TreeNode(postorder[pe]);
        int i=0;
        for(i=is;i<=ie;i++)
        {
            if(inorder[i]==postorder[pe])
            {
                break;
            }
        }
        root->left=helper(inorder,postorder,pe-ie+i-1,is,i-1);
        root->right=helper(inorder,postorder,pe-1,i+1,ie);
        return root;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<int> pr(n),in(n);
    cout<<"please input the inorder: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>pr[i];
    }
    cout<<"please input the postorder: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    TreeNode* root=s.buildTree(pr,in);
    fun(root);
    return 0;
}
