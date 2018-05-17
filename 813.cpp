#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n=A.size();
        memset(dp,0,sizeof(dp));
        double cur=0;
        for(int i=0;i<n;i++)
        {
            cur+=A[i];
            dp[i+1][1]=cur/(i+1);
        }
        dfs(n,K,A);
        return dp[n][K];
    }
private:
    double dp[103][103];
    double dfs(int n,int k,vector<int> &A)
    {
        if(dp[n][k])
        {
            return dp[n][k];
        }
        if(n<k)
        {
            return 0;
        }
        double cur=0;
        for(int i=n-1;i>0;--i)
        {
            cur+=A[i];
            dp[n][k]=max(dp[n][k],dfs(i,k-1,A)+cur/(n-i));
        }
        return dp[n][k];
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.largestSumOfAverages(v,k)<<endl;
    return 0;
}
