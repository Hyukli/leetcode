#include<iostream>
#include<map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode *pre=NULL,*slow=head,*fast=head;
        while(fast&&fast->next)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        return merge(l1,l2);
    }

private:
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode *l=new ListNode(0),*p=l;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                p->next=l1;
                l1=l1->next;
            }
            else
            {
                p->next=l2;
                l2=l2->next;
            }
            p=p->next;
        }
        if(l1)
        {
            p->next=l1;
        }
        else
        {
            p->next=l2;
        }
        return l->next;
    }
};

int main()
{
    int n;
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
    head=head->next;
    Solution s;
    head=s.sortList(head);

    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
