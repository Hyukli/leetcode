#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(v.size()==1)
            {
                if(nums[i]<v[0])
                {
                    v.push_back(v[0]);
                    v[0]=nums[i];
                }
                else if(nums[i]>v[0])
                {
                    v.push_back(nums[i]);
                }
            }
            else if(v.size()==2)
            {
                if(nums[i]<v[0])
                {
                    v.push_back(v[1]);
                    v[1]=v[0];
                    v[0]=nums[i];
                }
                else if(nums[i]>v[0]&&nums[i]<v[1])
                {
                    v.push_back(v[1]);
                    v[1]=nums[i];
                }
                else if(nums[i]>v[1])
                {
                    v.push_back(nums[i]);
                }
            }
            else if(v.size()==3)
            {
                if(nums[i]>v[0])
                {
                    if(nums[i]<v[1])
                    {
                        v[0]=nums[i];
                    }
                    else if(nums[i]>v[1])
                    {
                        if(nums[i]<v[2])
                        {
                            v[0]=v[1];
                            v[1]=nums[i];
                        }
                        else if(nums[i]>v[2])
                        {
                            v[0]=v[1];
                            v[1]=v[2];
                            v[2]=nums[i];
                        }
                    }
                }
            }
        }
        if(v.size()!=3)
        {
            return v[v.size()-1];
        }
        return v[0];
    }
};

int main()
{
    int n;
    vector<int> v;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    cout<<s.thirdMax(v)<<endl;
    return 0;
}
