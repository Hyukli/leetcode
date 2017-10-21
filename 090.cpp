#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        dfs(nums,0,v);
        return ans;
    }
private:
    vector<vector<int>> ans;
    int dfs(vector<int> nums,int i,vector<int> tmp)
    {
        ans.push_back(tmp);
        for(int j=i;j<nums.size();j++)
        {
            if(j==i||nums[j]!=nums[j-1])
            {
                tmp.push_back(nums[j]);
                dfs(nums,j+1,tmp);
                tmp.pop_back();
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
    vector<vector<int>> ans=s.subsetsWithDup(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<"[";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
