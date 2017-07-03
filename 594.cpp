#include<iostream>
#include<map>
#include<vetor>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        if(nums.size()==0||nums.size()==1)
        {
            return 0;
        }
        map<int,int> m;
        vector<int>  v;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]=1;
                v.push_back(nums[i]);
            }
            else
            {
                m[nums[i]]++;
            }
    	}
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            if(i+1<v.size()&&v[i+1]==v[i]+1)
            {
                if(m[v[i]]+m[v[i+1]]>ans)
                {
                    ans=m[v[i]]+m[v[i+1]];
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> v;
    Solution s;
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    cout<<s.findLHS(v)<<endl;
    return 0;
}
