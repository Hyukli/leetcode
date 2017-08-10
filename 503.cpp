#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution1 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=i+1;j<i+n;j++)
            {
                if(nums[j]>nums[i])
                {
                    ans.push_back(nums[j]);
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i=0;i<n*2;i++)
        {
            int num=nums[i%n];
            while(!s.empty()&&nums[s.top()]<num)
            {
                ans[s.top()]=num;
                s.pop();
            }
            if(i<n)
            {
                s.push(i);
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v(n),ans(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    ans=s.nextGreaterElements(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
