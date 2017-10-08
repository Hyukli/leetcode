#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0)
        {
            return 0;
        }
        int n=grid.size();
        int m=grid[0].size();
        int ma=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int k=0;
                    dfs(grid,i,j,k,n,m);
                    ma=max(ma,k);
                }
            }
        }
        return ma;
    }
private:
    int a[4]={-1,1,0,0};
    int b[4]={0,0,-1,1};
    int dfs(vector<vector<int>>& grid,int i,int j,int &k,int n,int m)
    {
        k++;
        grid[i][j]=0;
        for(int h=0;h<4;h++)
        {
            int ii=a[h]+i;
            int jj=b[h]+j;
            if(ii>=0&&ii<n&&jj>=0&&jj<m&&grid[ii][jj])
            {
                dfs(grid,ii,jj,k,n,m);
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
    vector<vector<int> > V(n,vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>V[i][j];
        }
    }
    cout<<s.maxAreaOfIsland(V)<<endl;
    return 0;
}
