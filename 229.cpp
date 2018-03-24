#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int c1=0,c2=0,a=0,b=1;
        for(auto n:nums)
        {
            if(n==a)
            {
                c1++;
            }
            else if(n==b)
            {
                c2++;
            }
            else if(c1==0)
            {
                c1=1;
                a=n;
            }
            else if(c2==0)
            {
                c2=1;
                b=n;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1=c2=0;
        for(auto n:nums)
        {
            if(a==n)    c1++;
            if(b==n)    c2++;
        }
        if(c1>nums.size()/3)    v.push_back(a);
        if(c2>nums.size()/3)    v.push_back(b);
        return v;
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
    vector<int> ans=s.majorityElement(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
