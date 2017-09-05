#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        for(int i=0;i<=target;i++)
        {
            dp.push_back(-1);
        }
        dp[0]=1;
        return fun(nums,target);
    }
    int fun(vector<int> nums,int target)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(target>=nums[i])
            {
                int k=target-nums[i];
                if(dp[k]!=-1)
                {
                    ans+=dp[k];
                }
                else
                {
                    ans+=(dp[k]=fun(nums,k));
                }
            }
        }
        return dp[target]=ans;
    }
private:
    vector<int> dp;
};

class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        int dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<target+1;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i-nums[j]>=0)
                {
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};

int main()
{
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    cout<<s.combinationSum4(v,t)<<endl;
    return 0;
}
