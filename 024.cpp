#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int n):val(n),next(NULL){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode *p= new ListNode(0);
        ListNode *q,*h;
        h=head->next;
        p->next=head;
        q=head;
        while(q!=NULL&&q->next!=NULL)
        {
            p->next=q->next;
            q->next=p->next->next;
            p->next->next=q;
            p=p->next->next;
            q=q->next;
        }
        return h;
    }
};

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
    h1=s.swapPairs(h1);
    while(h1!=NULL)
    {
        cout<<h1->val<<" ";
        h1=h1->next;
    }
    cout<<endl;
    return 0;
}
