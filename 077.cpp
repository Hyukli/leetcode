#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        dfs(n,k,0,0,v);
        return ans;
    }
private:
    vector<vector<int>> ans;
    int dfs(int n,int k,int i,int t,vector<int> v)
    {
        if(i==k)
        {
            ans.push_back(v);
            return 0;
        }
        for(int j=t+1;j<=n;j++)
        {
            v.push_back(j);
            dfs(n,k,i+1,j,v);
            v.pop_back();
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<vector<int>> ans;
    ans=s.combine(n,k);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
