#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>::iterator i=lower_bound(nums.begin(),nums.end(),target);
        vector<int>::iterator j=upper_bound(nums.begin(),nums.end(),target);
        vector<int> ans;
        ans.push_back(i-nums.begin());
        ans.push_back(j-nums.begin()-1);
        if(ans[1]<ans[0])
        {
            ans[0]=ans[1]=-1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int> ans=s.searchRange(v,t);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
