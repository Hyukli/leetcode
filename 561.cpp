#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nums;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i+=2)
        {
            ans+=nums[i];
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        nums.push_back(k);
    }
    Solution s;
    cout<<s.arrayPairSum(nums);
    return 0;
}
