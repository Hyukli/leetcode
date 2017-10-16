#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,vector<int>> m;
        int ma=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                vector<int> v;
                v.push_back(i);
                m[nums[i]]=v;
            }
            else
            {
                m[nums[i]].push_back(i);
            }
            if(m[nums[i]].size()>ma)
            {
                ma=m[nums[i]].size();
            }
        }
        int ll=nums.size();
        for(auto mm:m)
        {
            vector<int> v=mm.second;
            if(v.size()==ma)
            {
                ll=min(ll,v[v.size()-1]-v[0]+1);
            }
        }
        return ll;
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
    cout<<s.findShortestSubArray(v)<<endl;
    return 0;
}
