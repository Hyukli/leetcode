#include<iostream>
#include<strings.h>
#include<vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int a[10005];
        memset(a,0,sizeof(a));
        for(int i=0;i<nums.size();i++)
        {
            a[nums[i]]++;
        }
        int dp[10005];
        dp[1]=a[1];
        dp[2]=2*a[2];
        //cout<<"@@"<<endl;
        dp[3]=max(dp[2],dp[1]+3*a[3]);
        //cout<<"!!"<<endl;
        for(int i=4;i<=10000;i++)
        {
            dp[i]=max(dp[i-1],max(a[i]*i+dp[i-2],a[i]*i+dp[i-3]));
        }
        return dp[10000];
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
    cout<<s.deleteAndEarn(v)<<endl;
    return 0;
}
