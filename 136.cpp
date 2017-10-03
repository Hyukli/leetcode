#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int tmp=1;
        int ans=nums[0];
        int flag=0;
        for(int i=1;i<nums.size();i++)
        {
            if(tmp)
            {
                if(nums[i]!=nums[i-1])
                {
                    ans=nums[i-1];
                    flag++;
                    break;
                }
                else
                {
                    tmp^=1;
                }
            }
            else
            {
                tmp^=1;
            }
        }
        if(!flag)
        {
            ans=nums[nums.size()-1];
        }
        return ans;
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
    cout<<s.singleNumber(v)<<endl;
    return 0;
} 
