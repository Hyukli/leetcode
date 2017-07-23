#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end()&&i-m[nums[i]]<=k)
            {
                return true;
            }
            else
            {
                m[nums[i]]=i;
            }
        }
        return false;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    cout<<(s.containsNearbyDuplicate(v,m)?"Yes":"No")<<endl;
    return 0;
}
