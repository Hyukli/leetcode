#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0,j=nums.size()-1;i<j;i++,j--)
        {
            ans+=(nums[j]-nums[i]);
        }
        return ans;
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
    cout<<s.minMoves2(v)<<endl;
    return 0;
}
