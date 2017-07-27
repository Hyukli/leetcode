#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]=1;
            }
            else
            {
                m[nums[i]]++;
            }
        }
        if(k==0)
        {
            for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
            {
                if(i->second>1)
                {
                    ans++;
                }
            }
        }
        else if(k<0)
        {
            return 0;
        }
        else
        {
            for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
            {
                if(m.find(i->first+k)!=m.end())
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> v;
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    cout<<s.findPairs(v,m)<<endl;
    return 0;
}
