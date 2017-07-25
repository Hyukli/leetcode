#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        vector<int> s;
        s=nums;
        sort(s.begin(),s.end());
        int left=0;
        for(left;left<s.size();left++)
        {
            if(s[left]!=nums[left])
            {
                break;
            }
        }
        if(left==s.size())
        {
            return 0;
        }
        int right=s.size()-1;
        for(right;right>=0;right--)
        {
            if(s[right]!=nums[right])
            {
                break;
            }
        }
        return right-left+1;
    }
};

int main()
{
    Solution s;
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    cout<<s.findUnsortedSubarray(v)<<endl;
    return 0;
}
