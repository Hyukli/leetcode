#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n+2,1);
        for(int i=0;i<n;i++)
        {
            v[i+1]=nums[i];
        }
        n+=2;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int k=2;k<n;k++)
        {
            for(int left=0;left<n-k;left++)
            {
                int right=left+k;
                for(int i=left+1;i<right;i++)
                {
                    dp[left][right]=max(dp[left][right],v[left]*v[i]*v[right]+dp[left][i]+dp[i][right]);
                }
            }
        }
        return dp[0][n-1];
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
    cout<<s.maxCoins(v)<<endl;
    return 0;
}
