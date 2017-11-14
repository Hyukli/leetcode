#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int n):val(n),next(NULL){}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return bst(head,NULL);
    }
private:
    TreeNode* bst(ListNode* head,ListNode* tail)
    {
        if(head==tail)
        {
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=tail&&fast->next!=tail)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* p=new TreeNode(slow->val);
        p->left=bst(head,slow);
        p->right=bst(slow->next,tail);
        return p;
    }
};

int visit(TreeNode* p)
{
    if(p==NULL)
    {
        return 0;
    }
    cout<<p->val<<" ";
    visit(p->left);
    visit(p->right);
    return 0;
}

int main()
{
    int n;
    cout<<"please input the num of list:"<<endl;
    cin>>n;
    ListNode *h1=new ListNode(0);
    ListNode *t1=h1;
    cout<<"please input the val of the first list:"<<endl;
    while(n--)
    {
        int k;
        cin>>k;
        ListNode *p=new ListNode(k);
        t1->next=p;
        t1=t1->next;
    }
    h1=h1->next;
    Solution s;
    TreeNode* t=s.sortedListToBST(h1);
    visit(t);
    cout<<endl;
    return 0;
}
