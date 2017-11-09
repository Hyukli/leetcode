#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        n=grid.size();
        if(n==0)
        {
            return 0;
        }
        m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};
    int n,m;
    int dfs(vector<vector<char>>& grid,int i,int j)
    {
        grid[i][j]='0';
        for(int k=0;k<4;k++)
        {
            int xx=i+x[k];
            int yy=j+y[k];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&grid[xx][yy]=='1')
            {
                dfs(grid,xx,yy);
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<s.numIslands(v)<<endl;
    return 0;
}
