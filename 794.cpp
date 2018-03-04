#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int nx,ny;
        nx=ny=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]=='X')
                {
                    nx++;
                }
                else if(board[i][j]=='O')
                {
                    ny++;
                }
            }
        }
        if(!((nx==ny)||(nx==ny+1)))
        {
            return false;
        }
        int vx[8][3] = {{0,0,0},{1,1,1},{2,2,2},{0,1,2},{0,1,2},{0,1,2},{0,1,2},{0,1,2}};
        int vy[8][3] = {{0,1,2},{0,1,2},{0,1,2},{0,0,0},{1,1,1},{2,2,2},{0,1,2},{2,1,0}};
        int xx=0;
        int yy=0;
        for(int i=0;i<8;i++)
        {
            cout<<i<<" i"<<endl;
            cout<<vx[i][0]<<" "<<vy[i][0]<<endl;
            if(board[vx[i][0]][vy[i][0]]=='X'&&board[vx[i][1]][vy[i][1]]=='X'&&board[vx[i][2]][vy[i][2]]=='X')
            {

                xx++;
            }
            if(board[vx[i][0]][vy[i][0]]=='O'&&board[vx[i][1]][vy[i][1]]=='O'&&board[vx[i][2]][vy[i][2]]=='O')
            {
                yy++;
            }
        }
        cout<<xx<<" "<<yy<<endl;
        if(xx&&yy)
        {
            return false;
        }
        if(yy&&(nx>ny))
        {
            return false;
        }
        if(xx&&(nx==ny))
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> b(3);
    for(int i=0;i<3;i++)
    {
        cin>>b[i];
    }
    cout<<s.validTicTacToe(b)<<endl;
    return 0;
}
