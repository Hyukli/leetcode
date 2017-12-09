#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


bool cmp(const Interval& a,const Interval& b)
{
    return a.start<b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.size()==0)
        {
            return intervals;
        }
        sort(intervals.begin(),intervals.end(),cmp);
        int s=intervals[0].start;
        int e=intervals[0].end;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start<=e)
            {
                e=max(e,intervals[i].end);
            }
            else
            {
                ans.push_back(Interval(s,e));
                s=intervals[i].start;
                e=intervals[i].end;
            }
        }
        ans.push_back(Interval(s,e));
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<Interval> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].start>>v[i].end;
    }
    v=s.merge(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].start<<" "<<v[i].end<<endl;
    }
    return 0;
}
