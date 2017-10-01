#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        for(int i=1;i<=K;i++)
        {
            for(int j=0;j<N;j++)
            {
                for(int k=0;k<N;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        return dfs(r,c,K,N);
    }
private:
    double dp[100][25][25];
    vector<int> left={-1,-2,-2,-1,1,2,2,1};
    vector<int> up={-2,-1,1,2,2,1,-1,-2};
    double dfs(int i,int j,int K,int N)
    {
        double ans=0;
        if(K==0)
        {
            return 1;
        }
        for(int k=0;k<8;k++)
        {
            int ii=i+left[k];
            int jj=j+up[k];
            if(ii>=0&&jj>=0&&ii<N&&jj<N)
            {
                if(dp[K][ii][jj]!=-1)
                {
                    ans+=dp[K][ii][jj];
                }
                else
                {
                    ans+=0.125*dfs(ii,jj,K-1,N);
                    dp[K][ii][jj]=0.125*dfs(ii,jj,K-1,N);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,k,r,c;
    cin>>n>>k>>r>>c;
    cout<<s.knightProbability(n,k,r,c)<<endl;
    return 0;
}
