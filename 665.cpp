#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int> old=nums;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                nums[i]=nums[i-1];
                break;
            }
        }
        if(fun(nums))
        {
            return true;
        }
        nums=old;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                nums[i-1]=nums[i];
                break;
            }
        }
        if(fun(nums))
        {
            return true;
        }
        return false;
    }
private:
    bool fun(vector<int> nums)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<(s.checkPossibility(nums)?"Yes":"No")<<endl;
    return 0;
}
