#include<iostream>
#include<vector>
#include<strstream>
using namespace std;

string to_string(int n)
{
    strstream ss;
    ss<<n;
    string s;
    ss>>s;
    return s;
}

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string s="";
        if(nums.size()==1)
        {
            return to_string(nums[0]);
        }
        if(nums.size()==2)
        {
            s=to_string(nums[0])+"/"+to_string(nums[1]);
            return s;
        }
        s=to_string(nums[0])+"/(";
        s+=to_string(nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            s+="/";
            s+=to_string(nums[i]);
        }
        s+=")";
        return s;
    }
};

int main()
{
    int n;
    cin>>n;
    auto k=n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    cout<<s.optimalDivision(v)<<endl;
    return 0;
}
