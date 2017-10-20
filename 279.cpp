#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k*k<=i;k++)
            {
                dp[i]=min(dp[i],dp[i-k*k]+1);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.numSquares(n)<<endl;
    return 0;
}
