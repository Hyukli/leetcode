#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval
{
    int start,end;
};

bool cmp(const Interval &a,const Interval &b)
{
    if(a.end!=b.end)
    {
        return a.end<b.end;
    }
    else
    {
        return a.start>b.start;
    }
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        if(n==0)
        {
            return 0;
        }
        int b=intervals[0].end;
        int k=1;
        for(int i=1;i<n;i++)
        {
            if(intervals[i].start>=b)
            {
                b=intervals[i].end;
                k++;
            }
        }
        return n-k;
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
    cout<<s.eraseOverlapIntervals(v)<<endl;
    return 0;
}
