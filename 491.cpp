#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans,tmp,nums,0);
        return ans;
    }
private:
    int dfs(vector<vector<int>> &ans,vector<int> &tmp,vector<int> nums,int k)
    {
        if(tmp.size()>1)
        {
            ans.push_back(tmp);
        }
        map<int,int> m;
        for(int i=k;i<nums.size();i++)
        {
            if((tmp.empty()||tmp.back()<=nums[i])&&m.find(nums[i])==m.end())
            {
                tmp.push_back(nums[i]);
                dfs(ans,tmp,nums,i+1);
                tmp.pop_back();
                m[nums[i]]=1;
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
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<vector<int>> V=s.findSubsequences(v);
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
