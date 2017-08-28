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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
        {
            return NULL;
        }
        int mark=0;
        ListNode *fast=head->next->next;
        ListNode *slow=head->next;
        while(fast&&fast->next)
        {
            if(fast==slow)
            {
                mark++;
                break;
            }
            fast=fast->next->next;
            slow=slow->next;
        }
        if(mark==0)
        {
            return NULL;
        }
        fast=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};

int main()
{
    int n;
    cout<<"please input the num of node :"<<endl;
    cin>>n;
    ListNode *head=new ListNode(1);
    ListNode *tail=head;
    int mark=0;
    cout<<"please input the node one by one, the last node should be in the list before so we can get a circle list:"<<endl;
    while(n--)
    {
        int k;
        cin>>k;
        ListNode *p=head->next;
        mark=0;
        while(p)
        {
            if(p->val==k)
            {
                tail->next=p;
                mark++;
                break;
            }
            p=p->next;
        }
        if(!mark)
        {
            ListNode *q=new ListNode(k);
            tail->next=q;
            tail=tail->next;
        }
    }
    head=head->next;
    Solution s;
    cout<<s.detectCycle(head)->val<<endl;
    return 0;
}
