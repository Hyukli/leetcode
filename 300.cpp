#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            auto it=lower_bound(res.begin(),res.end(),nums[i]);
            if(it==res.end())
            {
                res.push_back(nums[i]);
            }
            else
            {
                *it=nums[i];
            }
        }
        return res.size();
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        int ans=1;
        int dp[10001];
        dp[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
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
    cout<<s.lengthOfLIS(v)<<endl;
    return 0;
}
