#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)    return head;
        n-=m;
        ListNode* prehead=new ListNode(0);
        prehead->next=head;
        ListNode* pre=prehead;
        while(--m)
        {
            pre=pre->next;
        }
        ListNode* pstart=pre->next;
        while(n--)
        {
            ListNode *p=pstart->next;
            pstart->next=p->next;
            p->next=pre->next;
            pre->next=p;
        }
        return prehead->next;
    }
};

int main()
{
    int n,m;
    ListNode *head =new ListNode(0);
    cin>>n;
    if(!n)
    {
        head=NULL;
    }
    ListNode *q=head;
    while(n--)
    {
        int k;
        cin>>k;
        ListNode *p= new ListNode(k);
        q->next=p;
        q=p;
    }
    cin>>m>>n;
    head=head->next;
    Solution s;
    head=s.reverseBetween(head,m,n);

    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
