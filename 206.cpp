#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};

class Solution1
{
public:
    ListNode *reverseList (ListNode *head)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode *res;
        ListNode *n=head->next;
        res=reverseList(n);

        head->next=NULL;
        n->next=head;
        return res;
    }
};

class Solution2
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode *first=NULL;
        ListNode *second=head;
        ListNode *third=NULL;
        while(second)
        {
            third=second->next;
            second->next=first;
            first=second;
            second=third;
        }
        return first;
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
    //Solution1 s1;
    Solution2 s2;
    //head=s1.reverseList(head);
    head=s2.reverseList(head);

    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
} 
