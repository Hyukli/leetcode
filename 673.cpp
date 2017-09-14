#include<iostream>
#include<vector>
using namespace std;

int a[2001][2001];
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                a[i][j]=0;
            }
            a[i][1]=1;
            a[i][0]=1;
        }
        int k=1;
        int tmp=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                k=a[i][0];
                if(nums[j]>nums[i])
                {
                    a[j][k+1]+=a[i][k];
                    tmp=max(tmp,k+1);
                    a[j][0]=max(a[j][0],k+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=a[i][tmp];
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
    cout<<s.findNumberOfLIS(v)<<endl;
    return 0;
}
