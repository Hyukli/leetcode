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
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1=new ListNode(0);
        ListNode *th=h1;
        th->next=NULL;
        ListNode *h2=new ListNode(0);
        ListNode *t=h2;
        h2->next=head;
        ListNode *cur=head,*next=NULL;
        while(cur)
        {
            next=cur->next;
            if(cur->val<x)
            {
                t->next=next;
                th->next=cur;
                th=cur;
                cur->next=NULL;
            }
            else
            {
                t=cur;
            }
            cur=next;
        }
        th->next=h2->next;
        return h1->next;
    }
};

int main()
{
    int n,k;
    cout<<"please input the num of list:"<<endl;
    cin>>n;
    cout<<"please input k:"<<endl;
    cin>>k;
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
    h1=s.partition(h1,k);
    while(h1!=NULL)
    {
        cout<<h1->val<<" ";
        h1=h1->next;
    }
    cout<<endl;
    return 0;
}
