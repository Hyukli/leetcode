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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *h=new ListNode(0);
        ListNode *t=h;
        while(l1&&l2)
        {
            if(l1->val>=l2->val)
            {
                t->next=l2;
                l2=l2->next;
            }
            else
            {
                t->next=l1;
                l1=l1->next;
            }
            t=t->next;
        }
        t->next=(l2?l2:l1);
        return h->next;
    }
};

int main()
{
    int n,m;
    cout<<"please input the num of two list:"<<endl;
    cin>>n>>m;
    ListNode *h1=new ListNode(0);
    ListNode *h2=new ListNode(0);
    ListNode *t1=h1;
    ListNode *t2=h2;
    cout<<"please input the val of the first list:"<<endl;
    while(n--)
    {
        int k;
        cin>>k;
        ListNode *p=new ListNode(k);
        t1->next=p;
        t1=t1->next;
    }
    cout<<"please input the val of the second list:"<<endl;
    while(m--)
    {
        int k;
        cin>>k;
        ListNode *p=new ListNode(k);
        t2->next=p;
        t2=t2->next;
    }
    h1=h1->next;
    h2=h2->next;
    Solution s;
    ListNode *p=s.mergeTwoLists(h1,h2);
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
    return 0;
}
