#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        dfs(candidates,0,target,0,v);
        return V;
    }
private:
    vector<vector<int>> V;
    int dfs(vector<int> &c,int i,int target,int tmp,vector<int> v)
    {
        if(target==tmp)
        {
            V.push_back(v);
            return 0;
        }
        if(i==c.size())
        {
            return 0;
        }
        for(int j=0;tmp+c[i]*j<=target;j++)
        {
            for(int k=0;k<j;k++)
            {
                v.push_back(c[i]);
            }
            dfs(c,i+1,target,tmp+c[i]*j,v);
            for(int k=0;k<j;k++)
            {
                v.pop_back();
            }
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
    vector<vector<int> > V=s.combinationSum(v,target);
    for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
