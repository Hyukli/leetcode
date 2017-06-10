#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> nums)
    {
        for(int i=0; i<nums.size(); i++)
        {
            nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);
        }
        vector<int> v;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>0)
            {
                v.push_back(i+1);
            }
        }
        return v;
    }
};

int main()
{
    vector<int>v;
    vector<int>ans;
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    ans=s.findDisappearedNumbers(v);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
