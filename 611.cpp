#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size();
        for(int i=n-1;i>1;i--)
        {
            int l=0,r=i-1;
            while(l<r)
            {
                if(nums[l]+nums[r]>nums[i])
                {
                    ans+=r-l;
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return ans;
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
    cout<<s.triangleNumber(v)<<endl;
    return 0;
}
