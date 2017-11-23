#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int k=0,ma=1;
        int n=nums.size();
        if(n==0)    return ans;
        vector<int> dp(n,1),par(n);
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<n;i++)    par[i]=i;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]%nums[i]!=0)
                {
                    continue;
                }
                if(dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    par[i]=j;
                }
                if(dp[i]>ma)
                {
                    ma=dp[i];
                    k=i;
                }
            }
        }
        while(par[k]!=k)
        {
            ans.push_back(nums[k]);
            k=par[k];
        }
        ans.push_back(nums[k]);
        return ans;
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
    vector<int> ans=s.largestDivisibleSubset(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
