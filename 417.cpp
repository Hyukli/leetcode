#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
        int m=matrix.size();
        if(m==0)
        {
            return ans;
        }
        int n=matrix[0].size();
        if(n==0)
        {
            return ans;
        }
        vector<vector<int>> v1(m,vector<int> (n,0));
        vector<vector<int>> v2(m,vector<int> (n,0));
        for(int i=0;i<n;i++)
        {
            v1[0][i]=1;
            dfs(v1,matrix,0,i);
        }
        for(int i=0;i<m;i++)
        {
            v1[i][0]=1;
            dfs(v1,matrix,i,0);
        }
        for(int i=0;i<n;i++)
        {
            v2[m-1][i]=1;
            dfs(v2,matrix,m-1,i);
        }
        for(int i=0;i<m;i++)
        {
            v2[i][n-1]=1;
            dfs(v2,matrix,i,n-1);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v1[i][j]==1&&v2[i][j]==1)
                {
                    ans.push_back(make_pair(i,j));
                }
            }
        }
        return ans;
    }
private:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int dfs(vector<vector<int>> &v,vector<vector<int>> ma,int x,int y)
    {
        v[x][y]=1;
        int m=v.size();
        int n=v[0].size();
        for(int i=0;i<4;i++)
        {
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1>=0&&x1<m&&y1>=0&&y1<n&&v[x1][y1]==0)
            {
                if(ma[x][y]<=ma[x1][y1])
                {
                    dfs(v,ma,x1,y1);
                }
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
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
    vector<pair<int, int>> ans=s.pacificAtlantic(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
