#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k<=0)    return false;
        if(k>nums.size())   k=nums.size();
        map<long long,long long> m;
        for(long long i=0;i<nums.size();i++)
        {
            if(k>t)
            {
                for(long long j=0;j<=t;j++)
                {
                    if(m.find(nums[i]-j)!=m.end()&&i-m[nums[i]-j]<=k)   return true;
                    if(m.find(nums[i]+j)!=m.end()&&i-m[nums[i]+j]<=k)   return true;
                }
            }
            else
            {
                for(long long j=1;j<=k;j++)
                {
                    if(i-j>=0)
                    {

                        long long x=(long long)nums[i-j]-(long long)nums[i];
                        if(x<0) x=-x;
                        if(x<=t)    return true;
                    }
                    if(i+j<nums.size())
                    {
                        long long y=(long long)nums[i+j]-(long long)nums[i];
                        if(y<0) y=-y;
                        if(y<=t)    return true;
                    }
                }
            }
            m[nums[i]]=i;
        }
        return false;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int k,t;
    cin>>k>>t;
    cout<<(s.containsNearbyAlmostDuplicate(v,k,t)?"Yes":"No")<<endl;
    return 0;
}
