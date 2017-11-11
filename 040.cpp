#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        dfs(candidates,v,0,target,0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    int dfs(vector<int> c,vector<int> v,int index,int target,int tmp)
    {
        if(tmp==target)
        {
            ans.push_back(v);
            return 0;
        }
        for(int i=index;i<c.size();i++)
        {
            if(c[i]+tmp>target)
            {
                return 0;
            }
            if(i&&c[i]==c[i-1]&&i>index)
            {
                continue;
            }
            v.push_back(c[i]);
            dfs(c,v,i+1,target,tmp+c[i]);
            v.pop_back();
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<vector<int>> ans=s.combinationSum2(v,target);
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
