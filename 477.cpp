#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        int max=nums[0];
        for(int num:nums)
        {
            if(num>max)
            {
                max=num;
            }
        }
        int n=weishu(max);
        int t1,t2,ans=0;
        for(int i=0;i<n;i++)
        {
            t1=t2=0;
            for(int j=0;j<nums.size();j++)
            {
                //cout<<nums[j]<<"  "<<(nums[j]&1)<<endl;
                if((nums[j]&1)==0)
                {
                    t1++;
                }
                else
                {
                    t2++;
                }
                nums[j]>>=1;
            }
            ans+=(t1*t2);
            //cout<<t1<<" "<<t2<<endl;
        }
        return ans;
    }
private:
    int weishu(int n)
    {
        int ans=0;
        while(n)
        {
            n>>=1;
            ans++;
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
    cout<<s.totalHammingDistance(v)<<endl;
    return 0;
}
