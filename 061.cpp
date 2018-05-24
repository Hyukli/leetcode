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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||!head)
        {
            return head;
        }
        int n=1;
        ListNode* t=head,*p=head;
        while(t->next)
        {
            n++;
            t=t->next;
        }
        k%=n;
        if(k==0)
        {
            return head;
        }
        k=n-k;
        while(--k)
        {
            p=p->next;
        }
        ListNode *nh=p->next;
        t->next=head;
        p->next=NULL;
        return nh;
    }
};

int main()
{
    int n,k;
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
    cout<<"please input the num of rotate the list:"<<endl;
    cin>>k;
    h1=h1->next;
    Solution s;
    h1=s.rotateRight(h1,k);
    while(h1!=NULL)
    {
        cout<<h1->val<<" ";
        h1=h1->next;
    }
    cout<<endl;
    return 0;
}

