#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        for(int i=1;i<nums.size();)
        {
            if(nums[i]==nums[i-1])
            {
                nums.erase(nums.begin()+i);
            }
            else
            {
                i++;
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution s;
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    cout<<s.removeDuplicates(v)<<endl;
    return 0;
} 
