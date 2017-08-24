#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> mark(nums.size(),false);
        vector<int> t;
        dfs(nums,mark,t,ans);
        return ans;
    }
private:
    int dfs(const vector<int> nums,vector<int> mark,vector<int> t,vector<vector<int>>& ans)
    {
        if(t.size()==nums.size())
        {
            ans.push_back(t);
            return 0;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mark[i]==false)
            {
                t.push_back(nums[i]);
                mark[i]=true;
                dfs(nums,mark,t,ans);
                mark[i]=false;
                t.pop_back();
            }
        }
        return 0;
    }
};

class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums,0,ans);
        return ans;
    }
private:
    int dfs(vector<int> v,int begin,vector<vector<int>>& ans)
    {
        if(begin>=v.size())
        {
            ans.push_back(v);
            return 0;
        }
        for(int i=begin;i<v.size();i++)
        {
            swap(v[i],v[begin]);
            dfs(v,begin+1,ans);
            swap(v[i],v[begin]);
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    vector<vector<int>> V;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    V=s.permute(v);
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
