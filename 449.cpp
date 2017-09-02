<<<<<<< HEAD
#include<iostream>
#include<sstream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<string.h>
using namespace std;

int a[1005];
int n,sum;

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        {
            return " #";
        }
        string ans=" "+to_string(root->val);
        return ans+serialize(root->left)+serialize(root->right);
    }

    TreeNode* dfs(stringstream &ss)
    {
        string str;
        ss>>str;
        if(str=="#")
        {
            return NULL;
        }
        TreeNode *p=new TreeNode(atoi(str));
        p->left=dfs(ss);
        p->right=dfs(ss);
        return p;
=======
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return " #";
        string ans = " "+to_string(root->val);
        return ans + serialize(root->left) + serialize(root->right); 
    }

    TreeNode* DFS(istringstream &is)
    {
        string str;
        is >> str;
        if(str == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        root->left = DFS(is), root->right = DFS(is);
        return root;
>>>>>>> 9f0de42ecf6e616f2cae993211750b62e19cf3e9
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
<<<<<<< HEAD
        stringstream ss(data);
        return dfs(ss);
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
    Codec codec;
    string s=codec.serialize(Root);
    cout<<s<<endl;
    return 0;
}
=======
        istringstream is(data);
        return DFS(is);
    }
};
>>>>>>> 9f0de42ecf6e616f2cae993211750b62e19cf3e9
