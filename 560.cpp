#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> sum;
        map<int,int> m;
        m[0]=1;
        int t=0,ans=0;
        for(int i=0;i<n;i++)
        {
            t+=nums[i];
            if(m.find(t-k)!=m.end())
            {
                ans+=m[t-k];
            }
            m[t]++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.subarraySum(v,k)<<endl;
    return 0;
}
