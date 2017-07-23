#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *h=new ListNode(0);
        h->next=head;
        head=h;
        while(h->next!=NULL)
        {
            if(h->next->val==val)
            {
                 h->next=h->next->next;
            }
            else
            {
                h=h->next;
            }
        }
        return head->next;
    }
};

int main()
{
    int n,m;
    ListNode *head =new ListNode(0);
    cin>>n>>m;
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
    head=s.removeElements(head,m);

    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
