  class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        int maxx=1;
        int tmp=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                tmp++;
                maxx=max(maxx,tmp);
            }
            else
            {
                tmp=1;
            }
        }
        return maxx;
    }
};
