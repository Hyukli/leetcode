#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)
        {
            return false;
        }
        int l=0,r=n-1;
        int mid=0;
        while(l<r)
        {
            mid=(l+r)/2;
            if(nums[mid]==target)   return true;
            if(nums[mid]>nums[r])
            {
                if(nums[mid]>target&&nums[l]<=target)   r=mid;
                else    l=mid+1;
            }
            else if(nums[mid]<nums[r])
            {
                if(nums[mid]<target&&nums[r]>=target)   l=mid+1;
                else    r=mid;
            }
            else
            {
                r--;
            }
        }
        return nums[l]==target;
    }
};

int main()
{
    Solution s;
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<(s.search(v,target)?"Yes":"No")<<endl;
    return 0;
}
