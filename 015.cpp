#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            int head=i+1;
            int back=n-1;
            int target=-nums[i];
            while(head<back)
            {
                int t=nums[head]+nums[back];
                if(t>target)
                {
                    back--;
                }
                else if(t<target)
                {
                    head++;
                }
                else
                {
                    vector<int> v(3,0);
                    v[0]=nums[i];
                    v[1]=nums[head];
                    v[2]=nums[back];
                    ans.push_back(v);
                    while(head<back&&nums[head]==v[1])  head++;
                    while(head<back&&nums[back]==v[2])  back--;
                }
            }
            while(i+1<n&&nums[i+1]==nums[i])    i++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<vector<int>> ans=s.threeSum(v);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
