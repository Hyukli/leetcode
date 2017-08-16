#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int n):val(n),next(NULL){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p=l1,*q=l2;
        vector<int> v1,v2,v;
        while(p)
        {
            v1.push_back(p->val);
            p=p->next;
        }
        while(q)
        {
            v2.push_back(q->val);
            q=q->next;
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        int flag=0,i;
        for(i=0;i<v1.size()&&i<v2.size();i++)
        {
            int t;
            t=v1[i]+v2[i]+flag;
            flag=0;
            if(t>=10)
            {
                t-=10;
                flag=1;
            }
            v.push_back(t);
        }
        int j=i;
        while(j<v1.size())
        {
            int t=v1[j]+flag;
            flag=0;
            if(t>=10)
            {
                t-=10;
                flag=1;
            }
            v.push_back(t);
            j++;
        }
        j=i;
        while(j<v2.size())
        {
            int t=v2[j]+flag;
            flag=0;
            if(t>=10)
            {
                t-=10;
                flag=1;
            }
            v.push_back(t);
            j++;
        }
        if(flag)
        {
            v.push_back(1);
        }
        reverse(v.begin(),v.end());
        ListNode *h=new ListNode(0);
        p=h;
        for(int i=0;i<v.size();i++)
        {
            p->val=v[i];
            ListNode *tmp=new ListNode(0);
            p->next=tmp;
            q=p;
            p=p->next;
        }
        q->next=NULL;
        return h;
    }
};

int main()
{
    int n,m;
    cout<<"please input the num of two list:"<<endl;
    cin>>n>>m;
    ListNode *h1=new ListNode(0);
    ListNode *h2=new ListNode(0);
    ListNode *t1=h1;
    ListNode *t2=h2;
    cout<<"please input the val of the first list:"<<endl;
    while(n--)
    {
        int k;
        cin>>k;
        ListNode *p=new ListNode(k);
        t1->next=p;
        t1=t1->next;
    }
    cout<<"please input the val of the second list:"<<endl;
    while(m--)
    {
        int k;
        cin>>k;
        ListNode *p=new ListNode(k);
        t2->next=p;
        t2=t2->next;
    }
    h1=h1->next;
    h2=h2->next;
    Solution s;
    ListNode *p=s.addTwoNumbers(h1,h2);
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
    return 0;
}
