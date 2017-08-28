#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()<2)
        {
            return -1;
        }
        int fast,slow;
        fast=nums[nums[0]];
        slow=nums[0];
        while(fast!=slow)
        {
            fast=nums[nums[fast]];
            slow=nums[slow];
        }
        fast=0;
        while(fast!=slow)
        {
            fast=nums[fast];
            slow=nums[slow];
        }
        return fast;
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
    cout<<s.findDuplicate(v)<<endl;
    return 0;
}
