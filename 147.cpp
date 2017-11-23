#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int n):val(n),next(NULL) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *helper=new ListNode(0);
        ListNode *pre=helper,*cur=head,*next=NULL;
        while(cur!=NULL)
        {
            next=cur->next;
            while(pre->next!=NULL&&pre->next->val<cur->val)
            {
                pre=pre->next;
            }
            cur->next=pre->next;
            pre->next=cur;
            pre=helper;
            cur=next;
        }
        return helper->next;
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
    h1=s.insertionSortList(h1);
    while(h1!=NULL)
    {
        cout<<h1->val<<" ";
        h1=h1->next;
    }
    cout<<endl;
    return 0;
}
