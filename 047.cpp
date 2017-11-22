#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    int dfs(vector<int> nums,int index)
    {
        if(index==nums.size()-1)
        {
            ans.push_back(nums);
            return 0;
        }
        for(int i=index;i<nums.size();i++)
        {
            if(index==i||nums[i]!=nums[index])
            {
                swap(nums[i],nums[index]);
                dfs(nums,index+1);
                //swap(nums[i],nums[index]);
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
    vector<vector<int>> ans=s.permuteUnique(v);
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
