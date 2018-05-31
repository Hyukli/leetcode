#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n,string(n,'.'));
        vector<int> flag(5*n-2,1);
        dfs(ans,v,flag,0,n);
        return ans.size();
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
    Solution s;
    int n;
    cin>>n;
    cout<<s.totalNQueens(n)<<endl;
    return 0;
}
