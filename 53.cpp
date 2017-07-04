#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        int ans=nums[0];
        int tmp=0;
        for(int i=0;i<nums.size();i++)
        {
            tmp+=nums[i];
            if(tmp>ans)
            {
                ans=tmp;
            }
            if(tmp<0)
            {
                tmp=0;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    cout<<s.maxSubArray(v)<<endl;
    return 0;
}
