#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0,two=0;
        for(int i=0;i<nums.size();i++)
        {13
            one=(one^nums[i])&~two;
            two=(two^nums[i])&~one;
        }
        return one;
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
    cout<<s.singleNumber(v)<<endl;
    return 0;
}
