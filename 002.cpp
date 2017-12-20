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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h=new ListNode(0);
        ListNode *tt=h;
        int tmp=0;
        while(l1!=NULL&&l2!=NULL)
        {
            int t=l1->val+l2->val+tmp;
            tmp=t/10;
            t%=10;
            ListNode *p=new ListNode(t);
            tt->next=p;
            tt=tt->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int t=l1->val+tmp;
            tmp=t/10;
            t%=10;
            ListNode *p=new ListNode(t);
            tt->next=p;
            tt=tt->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int t=l2->val+tmp;
            tmp=t/10;
            t%=10;
            ListNode *p=new ListNode(t);
            tt->next=p;
            tt=tt->next;
            l2=l2->next;
        }
        if(tmp==1)
        {
            ListNode *p=new ListNode(1);
            tt->next=p;
        }
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
    ListNode *p=s.addTwoNumbers(h1,h2);
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
    return 0;
}
