#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount+1,-1);
        dp[0]=0;
        for(long long i=0;i<=amount;i++)
        {
            if(dp[i]!=-1)
            {
                for(auto c:coins)
                {
                    if(i+c<=amount)
                    {
                        if(dp[i+c]==-1)
                        {
                            dp[i+c]=dp[i]+1;
                        }
                        else
                        {
                            dp[i+c]=min(dp[i+c],dp[i]+1);
                        }
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main()
{
    Solution s;
    int n,a;
    cin>>n>>a;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.coinChange(v,a)<<endl;
    return 0;
}
