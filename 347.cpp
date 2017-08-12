#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto n:nums)
        {
            m[n]++;
        }
        vector<vector<int>> v(nums.size()+1);
        for(auto mm:m)
        {
            v[mm.second].push_back(mm.first);
        }
        vector<int> ans;
        for(int i=v.size()-1;i>=0&&ans.size()<k;i--)
        {
            for(auto l:v[i])
            {
                ans.push_back(l);
            }
            if(ans.size()==k)
            {
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<int> v(n),ans;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    ans=s.topKFrequent(v,k);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
} 
