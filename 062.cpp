#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
        for(int i=0;i<101;i++)
        {
            dp[0][i]=1;
            dp[i][0]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if(m>n)
        {
            return c(m+n-2,n-1);
        }
        return c(m+n-2,m-1);
    }
private:
    long long c(int k,int n)
    {
        long long res=1;
        for(int i=0;i<n;i++)
        {
            res*=k--;
        }
        for(int i=2;i<=n;i++)
        {
            res/=i;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int m,n;
    cin>>m>>n;
    cout<<s.uniquePaths(m,n)<<endl;
    return 0;
}
