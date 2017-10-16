#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0)
        {
            return 0;
        }
        int n=grid[0].size();
        vector<vector<int>> V(m+1,vector<int> (n+1,INT_MAX));
        int k=m+n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                V[i+1][j+1]=grid[i][j];
            }
        }
        for(int i=3;i<=k;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i-j<1)
                {
                    break;
                }
                if(i-j<=n)
                {
                    V[j][i-j]+=min(V[j][i-j-1],V[j-1][i-j]);
                }
            }
        }
        return V[m][n];
    }
};

int main()
{
    Solution s;
    int m,n;
    cin>>m>>n;
    vector<vector<int>> V(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>V[i][j];
        }
    }
    cout<<s.minPathSum(V)<<endl;
    return 0;
}
