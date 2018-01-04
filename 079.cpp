#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0)
        {
            return true;
        }
        int m=board.size();
        if(m==0)    return false;
        int n=board[0].size();
        vector<vector<bool>> flag(m,vector<bool> (n,0));
        vector<vector<bool>> old=flag;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    flag=old;
                    flag[i][j]=1;
                    if(dfs(board,i,j,word,1,flag,m,n)) return true;
                }
            }
        }
        return false;
    }
private:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool dfs(vector<vector<char>> board,int i,int j,string word,int t,vector<vector<bool>> flag,int m,int n)
    {
        if(t==word.size())
        {
            return true;
        }
        for(int ii=0;ii<4;ii++)
        {
            int x=i+dx[ii];
            int y=j+dy[ii];
            if(x>=0&&x<m&&y>=0&&y<n&&flag[x][y]==0&&board[x][y]==word[t])
            {
                flag[x][y]=1;
                if(dfs(board,x,y,word,t+1,flag,m,n))    return true;
                flag[x][y]=0;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int m,n;
    cin>>m>>n;
    string ss;
    cin>>ss;
    vector<vector<char>> v(m,vector<char>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<(s.exist(v,ss)?"Yes":"No")<<endl;
    return 0;
}
