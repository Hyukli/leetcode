#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int tmp=1;
        ans[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            tmp*=nums[i-1];
            ans[i]=tmp;
        }
        tmp=1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            tmp*=nums[i+1];
            ans[i]*=tmp;
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v(n),ans(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    ans=s.productExceptSelf(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
