#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<findNums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(findNums[i]==nums[j])
                {
                    if(j==nums.size()-1)
                    {
                        v.push_back(-1);
                    }
                    else
                    {
                        for(int k=j+1;k<=nums.size();k++)
                        {
                            if(k==nums.size())
                            {
                                v.push_back(-1);
                                break;
                            }
                            else if(nums[k]>nums[j])
                            {
                                v.push_back(nums[k]);
                                break;
                            }
                        }
                    }

                }
            }
        }
        return v;
    }
};

int main()
{
    int n,m;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    cin>>n>>m;
    int k;
    while(n--)
    {
        cin>>k;
        a.push_back(k);
    }
    while(m--)
    {
        cin>>k;
        b.push_back(k);
    }
    Solution s;
    c=s.nextGreaterElement(a,b);
    for(int i=0;i<c.size();i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}
