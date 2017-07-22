#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double t=0;
        for(int i=0;i<k;i++)
        {
            t+=nums[i];
        }
        double tmp=t;
        double ans=t/k;
        for(int i=0;i+k<nums.size();i++)
        {
            t-=nums[i];
            t+=nums[i+k];
            if(t>tmp)
            {
                tmp=t;
                ans=t/k;
            }
        }
        return ans;
    }
};

int main()
{
    int n,m;
    vector<int> v;
    cin>>n>>m;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    cout<<s.findMaxAverage(v,m)<<endl;
    return 0;
}

