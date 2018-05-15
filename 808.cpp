#include<iostream>
#include<strings.h>
#include<vector>
using namespace std;

class Solution {
public:
    double soupServings(int N) {
        memset(dp,0,sizeof(dp));
        return N>=4800?1.0:dfs((N+24)/25,(N+24)/25);
    }
private:
    double dp[200][200];
    double dfs(int i,int j)
    {
        if(i<=0&&j<=0)
        {
            return 0.5;
        }
        if(i<=0)
        {
            return 1.0;
        }
        if(j<=0)
        {
            return 0.0;
        }
        if(dp[i][j]>0)
        {
            return dp[i][j];
        }
        return dp[i][j]=0.25*(dfs(i-4,j)+dfs(i-3,j-1)+dfs(i-2,j-2)+dfs(i-1,j-3));
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.soupServings(n)<<endl;
    return 0;
}
