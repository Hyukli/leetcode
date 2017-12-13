#include<iostream> 
using namespace std;

 struct ListNode
 {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* tmp=node->next;
        *node=*(node->next);
        delete tmp;
    }
};

int main()
{
    int n,m;
    cout<<"please input the number of the list size,"<<endl<<"and the number of the node that you wanna delete.";
    cin>>n>>m;
    ListNode *root=new ListNode(0);
    ListNode *r=root;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        ListNode *p=new ListNode(k);
        root->next=p;
        root=p;
    }
    ListNode *d=r;
    for(int i=0;i<m;i++)
    {
        d=d->next;
    }
    Solution s;
    s.deleteNode(d);
    for(int i=0;i<n-1;i++)
    {
        r=r->next;
        cout<<r->val<<" ";
    }
    return 0;
}
