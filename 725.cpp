#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int n):val(n),next(NULL){}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int sum=0;
        ListNode* p=root;
        while(p!=NULL)
        {
            sum++;
            p=p->next;
        }
        int n=sum/k;
        int m=sum%k;
        vector<int> v(k,n);
        vector<int> v2;
        for(int i=0;i<m;i++)
        {
            v[i]++;
        }
        v2.push_back(1);
        for(int i=0;i<k-1;i++)
        {
            v2.push_back(v2[i]+v[i]);
        }
        for(int i=1;i<v2.size();i++)
        {
            if(v2[i]<=v2[i-1])
            {
                v2[i]=v2[i-1]+1;
            }
            //cout<<v2[i]<<" ";
        }
        //cout<<endl;
        vector<ListNode*> ans;
        int tmp=0;
        int tt=0;
        p=root;
        sum=max(sum,k);
        cout<<endl;
        for(int i=0;i<sum;i++)
        {
            tmp++;
            //cout<<tmp<<" ";
            if(tmp==v2[tt])
            {
                ans.push_back(p);
                tt++;
            }
            if(p!=NULL)
            {
                p=p->next;
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            ListNode* qq=ans[i];
            for(int j=1;j<v[i];j++)
            {
                qq=qq->next;
            }
            if(qq!=NULL)
            {
                qq->next=NULL;
            }
        }
        return ans;
    }
};

int main()
{
    int n,k;
    cout<<"please input the num of list and k:"<<endl;
    cin>>n>>k;
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
    vector<ListNode*> v;
    v=s.splitListToParts(h1,k);
    for(int i=0;i<v.size();i++)
    {
        h1=v[i];
        while(h1!=NULL)
        {
            cout<<h1->val<<" ";
            h1=h1->next;
        }
        cout<<"#"<<endl;
    }

    cout<<endl;
    return 0;
}
