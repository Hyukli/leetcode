#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0)
        {
            return 0;
        }
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]-=48;
            }
        }
        vector<vector<int>> dp1(m,vector<int> (n,0));
        vector<vector<int>> dp2(m,vector<int> (n,0));
        vector<vector<int>> dp(m,vector<int> (n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    dp1[i][j]=matrix[i][j];
                }
                else
                {
                    if(matrix[i][j]==1)
                    {
                        dp1[i][j]=dp1[i][j-1]+1;
                    }
                    else
                    {
                        dp1[i][j]=0;
                    }
                }
                //cout<<dp1[i][j]<<" ";
            }
            //cout<<endl;
        }
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                if(i==0)
                {
                    dp2[i][j]=matrix[i][j];
                }
                else
                {
                    if(matrix[i][j]==1)
                    {
                        dp2[i][j]=dp2[i-1][j]+1;
                    }
                    else
                    {
                        dp2[i][j]=0;
                    }
                }
                //cout<<dp2[i][j]<<" ";
            }
            //cout<<endl;
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=matrix[i][j];
                }
                else
                {
                    if(matrix[i][j])
                    {
                        dp[i][j]=min(min(dp1[i][j],dp2[i][j]),dp[i-1][j-1]+1);
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
                ans=max(ans,dp[i][j]);
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        return ans*ans;
    }
};

int main()
{
    Solution s;
    int m,n;
    cin>>m>>n;
    vector<vector<char>> v(m,vector<char> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<s.maximalSquare(v)<<endl;
    return 0;
}
