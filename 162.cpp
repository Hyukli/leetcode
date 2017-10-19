#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.push_back(INT_MIN);
        nums.insert(nums.begin(),INT_MIN);
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
            {
                return i-1;
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
    cout<<s.findPeakElement(v)<<endl;
    return 0;
}
