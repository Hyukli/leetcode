#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a1[9][9]={0},a2[9][9]={0},a3[9][9]={0};
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int k=i/3*3+j/3;
                    int m=board[i][j]-'1';
                    if(a1[i][m]||a2[j][m]||a3[k][m])
                    {
                        return false;
                    }
                    a1[i][m]=a2[j][m]=a3[k][m]=1;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > V(9,vector<char> (9));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>V[i][j];
        }
    }
    cout<<(s.isValidSudoku(V)?"Yes":"No")<<endl;
    return 0;
}
