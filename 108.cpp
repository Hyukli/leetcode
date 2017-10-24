#include<iostream>
#include<vector>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         if(nums.size()==0)
         {
             return NULL;
         }
         return sortFromBegToEnd(nums,0,nums.size()-1);
    }
private:
    TreeNode* sortFromBegToEnd(vector<int>& nums,int beg,int end)
    {
        if(beg>end)
        {
            return NULL;
        }
        if(beg==end)
        {
            TreeNode *n = new TreeNode(nums[beg]);
            return n;
        }
        int mid=(beg+end)/2;
        TreeNode *m = new TreeNode(nums[mid]);
        m->left=sortFromBegToEnd(nums,beg,mid-1);
        m->right=sortFromBegToEnd(nums,mid+1,end);
        return m;
    }
};

int ldr(TreeNode *node)
{
    if(node->left!=NULL)
    {
        ldr(node->left);
    }
    cout<<node->val<<" ";
    if(node->right!=NULL)
    {
        ldr(node->right);
    }
    return 0;
}

int dlr(TreeNode *node)
{
    cout<<node->val<<" ";
    if(node->left!=NULL)
    {
        ldr(node->left);
    }
    if(node->right!=NULL)
    {
        ldr(node->right);
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    TreeNode* node;
    node=s.sortedArrayToBST(v);
    cout<<"LDR of the tree is ";
    ldr(node);
    cout<<endl<<"DLR of the tree is ";
    dlr(node);
    return 0;
}
