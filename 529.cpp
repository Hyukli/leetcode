#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<char> > updateBoard(vector<vector<char> >& board, vector<int>& click) {
        n=board.size();
        m=board[0].size();
        if(board[click[0]][click[1]]=='M')
        {
            board[click[0]][click[1]]='X';
            return board;
        }
        else
        {
            if(havem(click[0],click[1],board))
            {
                board[click[0]][click[1]]=havem(click[0],click[1],board)+'0';
            }
            else
            {
                dfs(click[0],click[1],board);
            }
        }
        return board;
    }
private:
    int n,m;
    vector<int> lr{-1,-1,0,1,1,1,0,-1};
    vector<int> ud{0,-1,-1,-1,0,1,1,1};
    int havem(int i,int j,vector<vector<char> > board)
    {
        int ans=0;
        for(int k=0;k<8;k++)
        {
            int ii=i+lr[k];
            int jj=j+ud[k];
            if(ii>=0&&ii<n&&jj>=0&&jj<m)
            {
                if(board[ii][jj]=='M')
                {
                    ans++;
                }
            }
        }
        return ans;
    }
    int dfs(int i,int j,vector<vector<char> >& board)
    {
        board[i][j]='B';
        for(int k=0;k<8;k++)
        {
            int ii=i+lr[k];
            int jj=j+ud[k];
            if(ii>=0&&ii<n&&jj>=0&&jj<m)
            {
                if(board[ii][jj]=='E')
                {
                    board[ii][jj]=havem(ii,jj,board)+'0';
                    if(board[ii][jj]=='0')
                    {
                        //cout<<ii<<" "<<jj<<endl;
                        dfs(ii,jj,board);
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    int n,m;
    cout<<"please input the height and width of the board:"<<endl;
    cin>>n>>m;
    cout<<"please input the board:"<<endl;
    vector<vector<char> > board,ans;
    for(int i=0;i<n;i++)
    {
        vector<char> v;
        for(int j=0;j<m;j++)
        {
            char k;
            cin>>k;
            v.push_back(k);
        }
        board.push_back(v);
    }
    cout<<"your board is:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"please input your click position:"<<endl;
    vector<int> click(2);
    cin>>click[0]>>click[1];
    Solution s;
    ans=s.updateBoard(board,click);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
