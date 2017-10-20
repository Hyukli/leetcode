#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        m=board.size();
        if(m==0)
        {
            return;
        }
        n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int k=liveN(board,i,j);
                //cout<<k<<endl;
                if(board[i][j]%10==1)
                {
                    if(k==2||k==3)
                    {
                        board[i][j]+=10;
                    }
                }
                else if(k==3)
                {
                    board[i][j]+=10;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j]/=10;
            }
        }
        return;
    }
private:
    int m,n;
    int dx[3]={-1,0,1};
    int dy[3]={-1,0,1};
    int liveN(vector<vector<int>>& board,int i,int j)
    {
        int ans=0;
        for(int k=0;k<3;k++)
        {
            for(int l=0;l<3;l++)
            {
                int ii=i+dx[k];
                int jj=j+dy[l];
                if((ii!=i||jj!=j)&&ii>=0&&ii<m&&jj>=0&&jj<n&&board[ii][jj]%10==1)
                {
                    ans++;
                }
            }
        }
        return ans;
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
    s.gameOfLife(v);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
