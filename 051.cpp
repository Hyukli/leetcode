#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n,string(n,'.'));
        dfs(v,ans,0,n);
        return ans;
    }
private:
    int dfs(vector<string> &v,vector<vector<string>> &ans,int rol,int n)
    {
        if(rol==n)  ans.push_back(v);
        for(int i=0;i<n;i++)
        {
            if(judge(v,n,rol,i))
            {
                v[rol][i]='Q';
                dfs(v,ans,rol+1,n);
                v[rol][i]='.';
            }
        }
        return 0;
    }

    bool judge(vector<string> &v,int n,int rol,int col)
    {
        for(int i=0;i!=rol;i++)
        {
            if(v[i][col]=='Q')  return false;
        }
        for(int i=rol-1,j=col-1;i>=0&&j>=0;i--,j--)
        {
            if(v[i][j]=='Q')    return false;
        }
        for(int i=rol-1,j=col+1;i>=0&&j<n;i--,j++)
        {
            if(v[i][j]=='Q')    return false;
        }
        return true;
    }
};

class Solution2 {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n,string(n,'.'));
        vector<int> flag(5*n-2,1);
        dfs(ans,v,flag,0,n);
        return ans;
    }
private:
    int dfs(vector<vector<string>> &ans,vector<string> &v,vector<int> &flag,int k,int n)
    {
        if(k==n)
        {
            ans.push_back(v);
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            if(flag[i]&&flag[n+k+i]&&flag[4*n+k-i-2])
            {
                flag[i]=flag[n+k+i]=flag[4*n+k-i-2]=0;
                v[k][i]='Q';
                dfs(ans,v,flag,k+1,n);
                v[k][i]='.';
                flag[i]=flag[n+k+i]=flag[4*n+k-i-2]=1;
            }
        }
        return 0;
    }
};

int main()
{
    Solution2 s;
    int n;
    cin>>n;
    vector<vector<string>> v=s.solveNQueens(n);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
