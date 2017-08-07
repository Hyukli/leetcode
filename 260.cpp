#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            tmp^=nums[i];
        }
        int k=1;
        while((k&tmp)==0)
        {
            k<<=1;
        }
        vector<int> v{0,0};
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&k)==0)
            {
                v[0]^=nums[i];
            }
            else
            {
                v[1]^=nums[i];
            }
        }
        return v;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    ans=s.singleNumber(v);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
