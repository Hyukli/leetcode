#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<Node>> ans;
        if(grid.size()==0)
        {
            return 0;
        }
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    vector<Node> v;
                    dfs(grid,i,j,v,i,j,n,m);
                    ans.push_back(v);
                }
            }
        }
        return nu(ans);
    }
private:
struct Node
{
    int x,y;
};
    int a[4]={1,-1,0,0};
    int b[4]={0,0,-1,1};
    int dfs(vector<vector<int>>& grid,int i,int j,vector<Node> &v,int i0,int j0,int n,int m)
    {
        grid[i][j]=0;
        for(int k=0;k<4;k++)
        {
            int ii=a[k]+i;
            int jj=b[k]+j;
            if(ii>=0&&ii<n&&jj>=0&&jj<m&&grid[ii][jj])
            {
                Node node;
                node.x=i0-ii;
                node.y=j0-jj;
                v.push_back(node);
                dfs(grid,ii,jj,v,i0,j0,n,m);
            }
        }
        return 0;
    }
    int nu(vector<vector<Node>> ans)
    {
        for(int i=0;i<ans.size();i++)
        {
            for(int j=i+1;j<ans.size();j++)
            {
                if(ans[i].size()==ans[j].size())
                {
                    int flag=0;
                    for(int k=0;k<ans[i].size();k++)
                    {
                        if(ans[i][k].x!=ans[j][k].x||ans[i][k].y!=ans[j][k].y)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        ans.erase(ans.begin()+j);
                        j--;
                    }
                }
            }
        }
        return ans.size();
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
    cout<<s.numDistinctIslands(V)<<endl;
    return 0;
}
