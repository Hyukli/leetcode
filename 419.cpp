#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char> >& board) {
        int ans=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='X')
                {
                    ans++;
                    board[i][j]=='.';
                    //cout<<i<<j<<endl;
                    dfs(board,i,j);
                }
            }
        }
        return ans;
    }
private:
    int dfs(vector<vector<char> >& board,int i,int j)
    {
        int n=i,m=j;
        while((++n)<board.size()&&board[n][m]=='X')
        {
            board[n][m]='.';
            //cout<<n<<" "<<m<<endl;
        }
        n=i,m=j;
        while((++m)<board[0].size()&&board[n][m]=='X')
        {
            board[n][m]='.';
        }
        return 0;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char> > V;
    for(int i=0;i<n;i++)
    {
        vector<char> v;
        for(int j=0;j<m;j++)
        {
            char k;
            cin>>k;
            v.push_back(k);
        }
        V.push_back(v);
    }
    Solution s;
    cout<<s.countBattleships(V)<<endl;
    return 0;
}
