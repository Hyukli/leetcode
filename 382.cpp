#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    Solution(ListNode* head)
    {
        p=head;
    }
    int getRandom() {
        int ans;
        ListNode *tmp;
        tmp=p;
        ans=tmp->val;
        for(int i=1;tmp;i++)
        {
            if(rand()%i==0)
            {
                ans=tmp->val;
            }
            tmp=tmp->next;
        }
        return ans;
    }
private:
    ListNode *p;
};

int main()
{
    int n;
    cout<<"please input the num of listnode:"<<endl;
    cin>>n;
    int m;
    cout<<"please input the time you wanna get random num:"<<endl;
    cin>>m;
    cout<<"please input the num one by one:"<<endl;
    ListNode *head=new ListNode(0);
    ListNode *p=head;
    while(n--)
    {
        int k;
        cin>>k;
        ListNode *t=new ListNode(k);
        p->next=t;
        p=p->next;
    }
    head=head->next;
    Solution obj = Solution(head);
    while(m--)
    {
        cout<<obj.getRandom()<<endl;
    }
    return 0;
}
