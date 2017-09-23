#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Node
{
    int s,e,no;
};

bool cmp(const Node &a,const Node &b)
{
    if(a.s!=b.s)
    {
       return a.s<b.s;
    }
    return a.no<b.no;
}

int binas(int k,vector<Node> v)
{
    int n=v.size()-1;
    int be=0;
    int en=n;
    while(en>=be)
    {
        int mid=(be+en)/2;
        if(v[mid].s>=k)
        {
            en=mid-1;
        }
        else
        {
            be=mid+1;
        }
    }
    return be<=n?be:-1;
}

class Solution1 {
public:
    vector<int> findRightInterval(vector<Interval>& intervals)
    {
        int n=intervals.size();
        vector<Node> v(n);
        for(int i=0;i<n;i++)
        {
            v[i].s=intervals[i].start;
            v[i].e=intervals[i].end;
            v[i].no=i;
        }
        vector<int> ans(n);
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<n;i++)
        {
            //cout<<v[i].s<<" "<<v[i].e<<" "<<v[i].no<<endl;
            int k=binas(v[i].e,v);
            if(k==-1)
            {
                ans[v[i].no]=-1;
            }
            else
            {
                ans[v[i].no]=v[k].no;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> findRightInterval(vector<Interval>& intervals)
    {
        int n=intervals.size();
        vector<Node> v(n);
        for(int i=0;i<n;i++)
        {
            v[i].s=intervals[i].start;
            v[i].e=intervals[i].end;
            v[i].no=i;
        }
        vector<int> ans(n);
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<n;i++)
        {
            ans[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[j].s>=v[i].e)
                {
                    ans[v[i].no]=v[j].no;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution1 s;
    vector<Interval> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].start>>v[i].end;
    }
    vector<int> ans=s.findRightInterval(v);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
