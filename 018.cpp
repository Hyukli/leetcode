#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {

            for(int j=i+1;j<n;j++)
            {
                if(j!=i+1&&nums[j]==nums[j-1])
                {
                    continue;
                }
                int target=tar-nums[i]-nums[j];
                int head=j+1;
                int tail=n-1;
                while(head<tail)
                {
                    int t=nums[head]+nums[tail];
                    if(t>target)
                    {
                        tail--;
                    }
                    else if(t<target)
                    {
                        head++;
                    }
                    else
                    {
                        vector<int> v(4,0);
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[head];
                        v[3]=nums[tail];
                        ans.push_back(v);
                        while(nums[head]==v[2]&&head<tail) head++;
                        while(nums[tail]==v[3]&&head<tail) tail--;
                    }
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
    int t;
    cin>>t;
    vector<vector<int>> ans=s.fourSum(v,t);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
