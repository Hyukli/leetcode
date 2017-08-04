#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n/2;
        while(lo<hi)
        {
            int m=(hi+lo)/2;
            if(nums[2*m]!=nums[2*m+1])
            {
                hi=m;
            }
            else
            {
                lo=m+1;
            }
        }
        return nums[lo*2];
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    cout<<s.singleNonDuplicate(v)<<endl;
    return 0;
}
