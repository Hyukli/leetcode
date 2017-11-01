#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==0)
        {
            return 0;
        }
        int tmp=nums[0];
        int flag=0;
        int i;
        int f=0;
        for(i=1;i<n;i++)
        {
            if(nums[i]!=tmp)
            {
                flag=nums[i]>tmp?1:0;
                tmp=nums[i];
                f++;
                break;
            }
        }
        if(!f)
        {
            return 1;
        }
        int ans=2;
        for(i++;i<n;i++)
        {
            if(nums[i]==tmp)
            {

            }
            else if(flag)
            {
                if(nums[i]<tmp)
                {
                    ans++;
                    tmp=nums[i];
                    flag=0;
                }
                else
                {
                    tmp=nums[i];
                }
            }
            else if(!flag)
            {
                if(nums[i]>tmp)
                {
                    ans++;
                    tmp=nums[i];
                    flag=1;
                }
                else
                {
                    tmp=nums[i];
                }
            }
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
    cout<<s.wiggleMaxLength(v)<<endl;
    return 0;
}
