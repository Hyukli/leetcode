#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int reach=0;i<n&&i<=reach;i++)
        {
            reach=max(i+nums[i],reach);
        }
        return i==n;
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
    cout<<(s.canJump(v)?"Yes":"No")<<endl;
    return 0;
}
