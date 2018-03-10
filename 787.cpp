#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int k=K+1;
        int v[102][102];
        memset(v,0,sizeof(v));
        for(int i=0;i<flights.size();i++)
        {
            v[flights[i][0]][flights[i][1]]=flights[i][2];
        }
        int dp[102][102];
        memset(dp,63,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            if(v[src][i])
            {
                dp[0][i]=v[src][i];
            }
        }
        for(int i=1;i<k;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int l=0;l<n;l++)
                {
                    if(v[j][l])
                    {
                        dp[i][l]=min(dp[i-1][j]+v[j][l],dp[i][l]);
                    }
                }
            }
        }
        for(int i=0;i<k;i++)
        {
            dp[k-1][dst]=min(dp[k-1][dst],dp[i][dst]);
        }
        if(dp[k-1][dst]==dp[101][101])
        {
            return -1;
        }
        return dp[k-1][dst];
    }
};

int main()
{
    Solution s;
    int n,m,ss,d,k;
    cin>>n>>m>>ss>>d>>k;
    vector<vector<int>> v(m,vector<int> (3));
    for(int i=0;i<m;i++)
    {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    cout<<s.findCheapestPrice(n,v,ss,d,k)<<endl;
    return 0;
}
