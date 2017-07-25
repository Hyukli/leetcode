#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int ,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]=1;
            }
            else
            {
                v.push_back(nums[i]);
            }
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(m.find(i)==m.end())
            {
                v.push_back(i);
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    int n;
    vector<int> v;
    vector<int> ans;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    ans=s.findErrorNums(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
