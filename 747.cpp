#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        int max1=-1,t=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>max1)
            {
                max1=nums[i];
                t=i;
            }
        }
        int max2=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=t&&nums[i]>max2)
            {
                max2=nums[i];
            }
        }
        if(max1>=max2*2)
        {
            return t;
        }
        return -1;
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
    cout<<s.dominantIndex(v)<<endl;
    return 0;
}
