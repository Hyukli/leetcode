#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if((sum&1)==1)
        {
            return false;
        }
        sum/=2;
        vector<bool> dp(sum,0);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=sum;j>=nums[i];j--)
            {
                dp[j]=dp[j]||dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<(s.canPartition(v)?"Yes":"No")<<endl;
    return 0;
}
