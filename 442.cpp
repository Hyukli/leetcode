#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        int i;
        for(i=0;i<nums.size();i++)
        {
            nums[i]--;
        }
        i=0;
        while(i<nums.size())
        {
            if(nums[i]!=nums[nums[i]])
            {
                swap(nums[i],nums[nums[i]]);
            }
            else
            {
                i++;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i)
            {
                v.push_back(nums[i]+1);
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v,ans;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    ans=s.findDuplicates(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
