#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                nums[i]=-1;
            }
        }
        int sum=0;
        map<int,vector<int>> m;
        m[0].push_back(-1);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            m[sum].push_back(i);
        }
        int ans=0;
        for(auto mm:m)
        {
            ans=max(ans,mm.second[mm.second.size()-1]-mm.second[0]);
        }
        return ans;
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
    cout<<s.findMaxLength(v)<<endl;
    return 0;
}
