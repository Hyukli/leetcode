#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         for(int i=nums.size()-2;i>=0;i--)
         {
             for(int j=nums.size()-1;j>i;j--)
             {
                if(nums[i]<nums[j])
                {
                    swap(nums[i],nums[j]);
                    //cout<<nums[0]<<" "<<nums[1]<<" "<<nums[2]<<endl;
                    reverse(nums.begin()+i+1,nums.end());
                    //cout<<nums[0]<<" "<<nums[1]<<" "<<nums[2]<<endl;
                    return;
                }
             }

         }
        reverse(nums.begin(),nums.end());
        return;
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
    s.nextPermutation(v);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
