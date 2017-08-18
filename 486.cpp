#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return digui(0,nums.size()-1,nums)>=0;
    }
    int digui(int i,int j,vector<int> nums)
    {
        if(i==j)
        {
            return nums[i];
        }
        return max(nums[i]-digui(i+1,j,nums),nums[j]-digui(i,j-1,nums));
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    cout<<(s.PredictTheWinner(v)?"Yes":"No")<<endl;
    return 0;
}
