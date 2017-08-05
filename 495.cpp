#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0)
        {
            return 0;
        }
        int ans=0;
        for(int i=0;i<timeSeries.size()-1;i++)
        {
            if(timeSeries[i]+duration<=timeSeries[i+1])
            {
                ans+=duration;
            }
            else
            {
                ans+=(timeSeries[i+1]-timeSeries[i]);
            }
        }
        ans+=duration;
        return ans;
    }
};

int main()
{
    Solution s;
    int d;
    int n;
    cin>>n>>d;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.findPoisonedDuration(v,d)<<endl;
    return 0;
}
