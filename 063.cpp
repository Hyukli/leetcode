#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        if(m==0)
        {
            return 0;
        }
        int n=obstacleGrid[0].size();
        if(n==0)
        {
            return 0;
        }
        vector<vector<int>> v(m,vector<int> (n,0));
        if(obstacleGrid[0][0]||obstacleGrid[m-1][n-1])
        {
            return 0;
        }
        v[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    continue;
                }
                if(i==0)
                {
                    if(obstacleGrid[i][j]==1)
                    {
                        break;
                    }
                    else
                    {
                        v[i][j]=v[i][j-1];
                    }
                }
                else if(j==0)
                {
                    if(obstacleGrid[i][j]==1)
                    {
                        v[i][j]=0;
                    }
                    else
                    {
                        v[i][j]=v[i-1][j];
                    }
                }
                else
                {
                    if(obstacleGrid[i][j]==1)
                    {
                        continue;
                    }
                    else
                    {
                        v[i][j]=v[i-1][j]+v[i][j-1];
                    }
                }
            }
        }
        return v[m-1][n-1];
    }
};

int main()
{
    Solution s;
    int m,n;
    cin>>m>>n;
    vector<vector<int> > v(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<s.uniquePathsWithObstacles(v)<<endl;
    return 0;
}
