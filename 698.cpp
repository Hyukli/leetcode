#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool dfs(vector<int> &nums, int idx, vector<int> &sums, int n, int &k, int &sum) {
        if (n == idx) {
            return true;
        }
        for (int i = 0; i < k; i++) {
            if (sums[i] + nums[idx] > sum) {
                continue;
            }
            sums[i] += nums[idx];
            if (dfs(nums, idx + 1, sums, n, k, sum)) {
                return true;
            }
            sums[i] -= nums[idx];
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % k != 0) {
            return false;
        }
        sum /= k;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        vector<int> sums(k);
        return dfs(nums, 0, sums, nums.size(), k, sum);
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
    cout<<(s.canPartitionKSubsets(v,k)?"Yes":"No")<<endl;
    return 0;
}
