#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int first=0,second=0;
        for(int i=0;i<nums.size();i++)
        {
            first=(nums[i]^first)&~second;
            second=(nums[i]^second)&~first;
        }
        return first;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    cout<<s.singleNumber(v)<<endl;
    return 0;
}
