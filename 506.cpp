#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank;
        vector<string> ans;
        for(int i=0;i<nums.size();i++)
        {
            int tmp=1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    rank[j]++;
                }
                else
                {
                    tmp++;
                }
            }
            rank.push_back(tmp);
        }
        for(int i=0;i<rank.size();i++)
        {
            if(rank[i]==1)
            {
                ans.push_back("Gold Medal");
            }
            else if(rank[i]==2)
            {
                ans.push_back("Silver Medal");
            }
            else if(rank[i]==3)
            {
                ans.push_back("Bronze Medal");
            }
            else
            {
                ans.push_back(tostr(rank[i]));
            }
        }
        return ans;
    }
private:
    string tostr(int i)
    {
        string s;
        stringstream ss;
        ss<<i;
        ss>>s;
        return s;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    vector<string> ans;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution sss;
    ans=sss.findRelativeRanks(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
