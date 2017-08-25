#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* odd=head,* eve=head->next,* eh=eve;
        while(odd->next!=NULL&&eve->next!=NULL)
        {
            odd->next=odd->next->next;
            eve->next=eve->next->next;
            odd=odd->next;
            eve=eve->next;
        }
        odd->next=eh;
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
    Solution s;
    head=s.oddEvenList(head);

    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
