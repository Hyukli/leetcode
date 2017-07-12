#include<iostream>
#include<vector>
using namespace std;

int a[1005];
int n;

struct TreeNode
{
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
    vector<int> findMode(TreeNode* root) {
        lmr(root);
        return v;
    }
private:
    vector<int> v;
    int max=-1;
    int tmp=-1;
    int cnt=1;
    int lmr(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else
        {
            lmr(root->left);
            if(root->val!=tmp)
            {
                cnt=1;
                tmp=root->val;
            }
            else
            {
                cnt++;
            }
            if(cnt==max)
            {
                v.push_back(tmp);
            }
            else if(cnt>max)
            {
                v.clear();
                v.push_back(tmp);
                max=cnt;
            }
            lmr(root->right);
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
    vector<int> v;
    v=kk.findMode(Root);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}

