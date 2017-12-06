#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int sum;
        if(n<3)
        {
            sum=0;
            for(auto m:nums)    sum+=m;
            return sum;
        }
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<abs(ans-target))
                {
                    ans=sum;
                    if(ans==target)
                    {
                        return ans;
                    }
                }
                if(sum>target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.threeSumClosest(v,t)<<endl;
    return 0;
}
