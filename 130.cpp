#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        if(n==0)    return ;
        int m=board[0].size();
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')    dfs(board,0,i);
            if(board[n-1][i]=='O')  dfs(board,n-1,i);
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')    dfs(board,i,0);
            if(board[i][m-1]=='O')  dfs(board,i,m-1);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                board[i][j]='X';
            }
        }
        for(int i=0;i<v.size();i++)
        {
            board[v[i].first][v[i].second]='O';
        }
        return ;
    }
private:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    vector<pair<int,int>> v;
    int dfs(vector<vector<char>> &board,int i,int j)
    {
        v.push_back(make_pair(i,j));
        board[i][j]='X';
        int n=board.size();
        int m=board[0].size();
        for(int x=0;x<4;x++)
        {
            int nx=i+dx[x];
            int ny=j+dy[x];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&board[nx][ny]=='O')
            {
                dfs(board,nx,ny);
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
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<endl;
    s.solve(v);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
