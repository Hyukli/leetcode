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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
        {
            return false;
        }
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(slow!=fast)
        {
            if(slow->next==NULL||fast->next==NULL||fast->next->next==NULL)
            {
                return false;
            }
            else
            {
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        return true;
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
    cout<<(s.hasCycle(h1)?"Yes":"No")<<endl;
    return 0;
}
