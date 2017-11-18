#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n),dp2(n);
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return nums[0];
        }
        else if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        dp1[0]=nums[0];
        dp1[1]=max(dp1[0],nums[1]);
        for(int i=2;i<n-1;i++)
        {
            dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
        }
        dp2[0]=0;
        dp2[1]=nums[1];
        for(int i=2;i<n;i++)
        {
            dp2[i]=max(dp2[i-1],dp2[i-2]+nums[i]);
        }
        return max(dp1[n-2],dp2[n-1]);
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
    cout<<s.rob(v)<<endl;
    return 0;
}
