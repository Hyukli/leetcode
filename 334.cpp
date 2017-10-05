#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x1=INT_MAX,x2=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=x1)
            {
                x1=nums[i];
            }
            else if(nums[i]<=x2)
            {
                x2=nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
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
    cout<<(s.increasingTriplet(v)?"Yes":"No")<<endl;
    return 0;
}
