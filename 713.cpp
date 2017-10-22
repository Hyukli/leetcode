#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        if(k==0||k==1)
        {
            return 0;
        }
        long long tmp=1;
        int be=0,en=0;
        for(;en<n;en++)
        {
            tmp*=nums[en];
            if(tmp<k)
            {
                ans+=(en-be+1);
            }
            else
            {
                while(tmp>=k)
                {
                    tmp/=nums[be++];
                }
                ans+=(en-be+1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.numSubarrayProductLessThanK(v,k)<<endl;
    return 0;
}
