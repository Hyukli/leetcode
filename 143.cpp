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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        {
            return ;
        }
        ListNode* tail=head,*pt;
        while(tail->next!=NULL)
        {
            pt=tail;
            tail=tail->next;
        }
        pt->next=NULL;
        tail->next=head->next;
        head->next=tail;
        head=head->next->next;
        reorderList(head);
        return ;
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
    s.reorderList(h1);
    while(h1!=NULL)
    {
        cout<<h1->val<<" ";
        h1=h1->next;
    }
    cout<<endl;
    return 0;
}
