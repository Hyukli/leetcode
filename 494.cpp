#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        dfs(0,0,nums,S);
        return result;
    }
private:
    int result=0;
    int dfs(int sum,int cnt,vector<int>& nums,int  S)
    {
        if(cnt==nums.size())
        {
            if(sum==S)
            {
                result++;
            }
            return 0;
        }
        dfs(sum+nums[cnt],cnt+1,nums,S);
        dfs(sum-nums[cnt],cnt+1,nums,S);
        return 0;
    }
};

int main()
{
    Solution s;
    int n,S;
    cin>>n>>S;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.findTargetSumWays(v,S)<<endl;
    return 0;
}
