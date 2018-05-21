#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K==0||K+W<=N)    return 1.0;
        vector<double> dp(N+1,0);
        double wsum=1.0,ans=0.0;
        dp[0]=1.0;
        for(int i=1;i<=N;i++)
        {
            dp[i]=wsum/W;
            if(i<K) wsum+=dp[i];    else    ans+=dp[i];
            if(i-W>=0)  wsum-=dp[i-W];
        }
        return ans;
    }
};

class Solution2 {
public:
    double new21Game(int N, int K, int W) {
        double dp[20005];
        memset(dp,0,sizeof(dp));
        dp[0]=1.0;
        dp[1]=-1.0;
        double val=0;
        for(int i=0;i<K;i++)
        {
            val+=dp[i];
            dp[i+1]+=val/W;
            dp[i+1+W]-=val/W;
        }
        double ans=0;
        for(int i=K;i<=N;i++)
        {
            val+=dp[i];
            ans+=val;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,k,w;
    cin>>n>>k>>w;
    cout<<s.new21Game(n,k,w)<<endl;
    return 0;
}
