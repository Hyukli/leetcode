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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1=head,*p2=head;
        for(int i=0;i<n;i++)
        {
            p2=p2->next;
        }
        if(p2==NULL)
        {
            return head->next;
        }
        while(p2->next!=NULL)
        {
            p2=p2->next;
            p1=p1->next;
        }
        p1->next=p1->next->next;
        return head;
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
    int k;
    cout<<"please input the num you wanna delete:"<<endl;
    cin>>k;
    h1=h1->next;
    Solution s;
    h1=s.removeNthFromEnd(h1,k);
    while(h1!=NULL)
    {
        cout<<h1->val<<" ";
        h1=h1->next;
    }
    cout<<endl;
    return 0;
}
