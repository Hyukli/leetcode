#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        if(!nums.size())
        {
            return false;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]==0;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size()>set<int>(nums.begin(),nums.end()).size();
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    cout<<(s.containsDuplicate(v)?"Yes":"No")<<endl;
    return 0;
}
