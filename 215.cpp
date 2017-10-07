#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        nth_element(nums.begin(),nums.begin()+n-k,nums.end());
        return nums[n-k];
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.findKthLargest(v,k)<<endl;
    return 0;
}
