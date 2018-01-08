#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

bool cmp(const Interval& a,const Interval& b)
{
    if(a.start==b.start)
    {
        return a.end<b.end;
    }
    return a.start<b.start;
}

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> v;
        for(int i=0;i<schedule.size();i++)
        {
            for(int j=0;j<schedule[i].size();j++)
            {
                v.push_back(schedule[i][j]);
            }
        }
        sort(v.begin(),v.end(),cmp);
        vector<Interval> vv;
        int s=v[0].start;
        int t=v[0].end;
        for(int i=1;i<v.size();i++)
        {
            if(v[i].start<=t)
            {
                t=max(t,v[i].end);
            }
            else
            {
                vv.push_back(Interval(s,t));
                s=v[i].start;
                t=v[i].end;
            }
        }
        vv.push_back(Interval(s,t));
        vector<Interval> ans;
        for(int i=0;i<vv.size()-1;i++)
        {
            ans.push_back(Interval(vv[i].end,vv[i+1].start));
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<vector<Interval>> V;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        vector<Interval> v(m);
        for(int i=0;i<m;i++)
        {
            cin>>v[i].start>>v[i].end;
        }
        V.push_back(v);
    }
    vector<Interval> ans=s.employeeFreeTime(V);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].start<<" "<<ans[i].end<<endl;
    }
    return 0;
}
