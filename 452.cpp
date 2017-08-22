#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.first!=b.first)
    {
        return a.first<b.first;
    }
    return a.second<b.second;
}

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size()==0)
        {
            return 0;
        }
        sort(points.begin(),points.end(),cmp);
        int ans=1;
        int tmp=points[0].second;
        for(int i=1;i<points.size();i++)
        {
            if(points[i].first<=tmp)
            {
                tmp=min(tmp,points[i].second);
            }
            else
            {
                ans++;
                tmp=points[i].second;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    cout<<s.findMinArrowShots(v)<<endl;
    return 0;
}
