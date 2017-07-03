#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode *p=head;
        while(p->next!=NULL)
        {
            if(p->val==p->next->val)
            {
                p->next=p->next->next;
            }
            else
            {
                p=p->next;
            }
        }
        return head;
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
    Solution2 s;
    head=s.deleteDuplicates(head);

    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
} 
