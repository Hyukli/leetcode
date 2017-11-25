#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>> v(n,vector<int> (m,INT_MAX));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    v[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    dfs(v,i,j,0);
                }
            }
        }
        return v;
    }
private:
    int n,m;
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};

    int dfs(vector<vector<int>>& v,int i,int j,int k)
    {
        v[i][j]=k;
        for(int ii=0;ii<4;ii++)
        {
            int dx=i+x[ii];
            int dy=j+y[ii];
            if(dx>=0&&dx<n&&dy>=0&&dy<m&&v[dx][dy]>k+1)
            {
                dfs(v,dx,dy,k+1);
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> ans;
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    ans=s.updateMatrix(v);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
