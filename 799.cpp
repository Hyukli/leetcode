#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        memset(dp,0,sizeof(dp));
        dp[0][0]=poured;
        return dfs(0,query_row,query_glass);
    }
private:
    double dp[200][200];
    double dfs(int dep,int r,int g)
    {
        for(int i=0;i<=dep;i++)
        {
            if(dp[dep][i]>1.0)
            {
                double df=(dp[dep][i]-1.0)/2.0;
                dp[dep+1][i]+=df;
                dp[dep+1][i+1]+=df;
                dp[dep][i]=1.0;
            }
        }
        if(dep==r)
        {
            return dp[r][g];
        }
        return dfs(dep+1,r,g);
    }
};

int main()
{
    Solution s;
    int n,i,j;
    cin>>n>>i>>j;
    cout<<s.champagneTower(n,i,j)<<endl;
    return 0;
}
