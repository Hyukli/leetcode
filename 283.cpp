#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                for(int j=i+1;j<nums.size();j++)
                {
                    if(nums[j])
                    {
                        nums[i]=nums[j];
                        nums[j]=0;
                        break;
                    }
                }
            }
        }
    }
};

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    s.moveZeroes(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
