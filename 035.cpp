#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        int mark=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]>=target)
            {
                mark++;
                break;
            }
        }
        return i;
    }
};

int main()
{
    Solution s;
    int n,t;
    cin>>n>>t;
    vector<int> v;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    cout<<s.searchInsert(v,t)<<endl;
    return 0;
}
