#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int r=nums[0];
        for(int i=1,maxx=r,minn=r;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(maxx,minn);
            }
            minn=min(nums[i],minn*nums[i]);
            maxx=max(nums[i],maxx*nums[i]);
            r=max(maxx,r);
        }
        return r;
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
    cout<<s.maxProduct(v)<<endl;
    return 0;
}
