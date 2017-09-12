#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        int tmp=1;
        int ans=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                tmp++;
                ans=max(ans,tmp);
            }
            else
            {
                tmp=1;
            }
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
    cout<<s.findLengthOfLCIS(v)<<endl;
    return 0;
}
