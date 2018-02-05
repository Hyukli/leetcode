#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=1;i<nums1.size();i++)
        {
            if(nums1[i]==nums1[i-1])
            {
                nums1.erase(nums1.begin()+i);
                i--;
            }
        }
        for(int i=1;i<nums2.size();i++)
        {
            if(nums2[i]==nums2[i-1])
            {
                nums2.erase(nums2.begin()+i);
                i--;
            }
        }
        vector<int> v;
        for(int i=0, j=0;i<nums1.size()&&j<nums2.size();)
        {
            if(nums1[i]==nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return v;
    }
};

int main()
{
    int n,m,t;
    cin>>n>>m;
    vector<int> nums1,nums2,ans;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        nums1.push_back(t);
    }
    for(int i=0;i<m;i++)
    {
        cin>>t;
        nums2.push_back(t);
    }
    Solution ss;
    ans=ss.intersection(nums1,nums2);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
