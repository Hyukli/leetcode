#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end()&&m[target-nums[i]]!=i)
            {
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
                break;
            }
        }
        return v;
    }
};

int main()
{
    int n,result;
    cin>>n>>result;
    vector<int> a,v;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    a=s.twoSum(v,result);
    cout<<a[0]<<" "<<a[1]<<endl;
    return 0;
}
