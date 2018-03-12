#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numTilings(int N) {
        int md=1e9;
        md+=7;
        vector<long long> dp(1004);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=N;i++)
        {
            dp[i]=2*dp[i-1]+dp[i-3];
            dp[i]%=md;
        }
        return dp[N];
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.numTilings(n)<<endl;
    return 0;
}
