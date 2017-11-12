#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long sum=0;
        for(int n:nums)
        {
            sum+=n;
        }
        long long tmp=0;
        for(int i=0;i<nums.size();i++)
        {
            if(tmp*2==sum-nums[i])
            {
                return i;
            }
            tmp+=nums[i];
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
    cout<<s.pivotIndex(v)<<endl;
    return 0;
}
