#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int findPaths(int m, int n, int N, int i, int j)
    {
        long long dp[51][50][50];
        for(auto Ni=1; Ni<=N; Ni++)
        {
            for(auto mi=0; mi<m; mi++)
            {
                for(auto ni=0; ni<n; ni++)
                {
                    dp[Ni][mi][ni] = ((mi == 0 ? 1 : dp[Ni - 1][mi - 1][ni]) + (mi == m - 1? 1 : dp[Ni - 1][mi + 1][ni])+ (ni == 0 ? 1 : dp[Ni - 1][mi][ni - 1]) + (ni == n - 1 ? 1 : dp[Ni - 1][mi][ni + 1])) % 1000000007;
                }
            }
        }
        return dp[N][i][j];
    }
};

int main()
{
    Solution s;
    int m,n,N,i,j;
    cin>>m>>n>>N>>i>>j;
    cout<<s.findPaths(m,n,N,i,j)<<endl;
    return 0;
}
