#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return true;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=slow->next;
        slow=reverseList(slow);
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
            {
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
private:
    ListNode *reverseList(ListNode* head)
    {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL)
        {
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
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
    cout<<(s.isPalindrome(head)?"Yes":"No")<<endl;
    return 0;
}
