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

class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        if(nums.size()==0)
        {
            return ans;
        }
        int start=0;
        int end=nums.size()-1;
        int mid=(start+end)/2;
        //cout<<"!!"<<endl;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(nums[mid]==target)
            {
                break;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        //cout<<"!!"<<endl;
        if(mid<0||mid>nums.size()-1||nums[mid]!=target)
        {
            return ans;
        }
        int i=mid,j=mid;
        while(i>=0&&nums[i]==target)    i--;
        while(j<nums.size()&&nums[j]==target)   j++;
        ans[0]=i+1;
        ans[1]=j-1;
        return ans;
    }
};

int main()
{
    //Solution s;
    Solution2 s;
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
