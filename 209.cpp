#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l=0,r=0,sum=0;
        int k=nums.size();
        int ans=k+1;
        for(;;)
        {
            while(r<k&&sum<s)
            {
                sum+=nums[r++];
            }
            if(sum<s)
            {
                break;
            }
            ans=min(r-l,ans);
            sum-=nums[l++];
        }
        if(ans>k)
        {
            ans=0;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int k,n;
    cin>>k>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.minSubArrayLen(k,v)<<endl;
    return 0;
}
