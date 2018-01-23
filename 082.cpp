#include<iostream>
#include<map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* h=new ListNode(0);
        map<int,int> m;
        h->next=head;
        while(head!=NULL)
        {
            m[head->val]++;
            head=head->next;
        }
        head=h->next;
        ListNode* p=h;
        while(head!=NULL)
        {
            if(m[head->val]!=1)
            {
                p->next=head->next;
                head=p->next;
            }
            else
            {
                p=head;
                head=head->next;
            }
        }
        return h->next;
    }
};

class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        int val=head->val;
        ListNode* p=head->next;
        if(p->val!=val)
        {
            head->next=deleteDuplicates(p);
            return head;
        }
        else
        {
            while(p&&p->val==val)   p=p->next;
            return deleteDuplicates(p);
        }
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
    head=s2.deleteDuplicates(head);

    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
