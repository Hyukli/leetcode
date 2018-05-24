#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k==0)
        {
            int flag=0;
            for(auto n:nums)
            {
                if(flag&&n==0)  return true;
                if(!flag&&n==0) flag=1;
                if(n)   flag=0;
            }
            return false;
        }
        k=abs(k);
        long long tmp=0;
        long long in;
        set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            in=tmp;
            tmp+=nums[i];
            tmp%=k;
            if(s.count(tmp)==1) return true;
            else    s.insert(in);
        }
        return false;
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
    cout<<(s.checkSubarraySum(v,k)?"Yes":"No")<<endl;
    return 0;
}
