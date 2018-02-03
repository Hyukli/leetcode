#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=0,j=0;i<nums1.size()&&j<nums2.size();)
        {
            if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a,b,c;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        a.push_back(k);
    }
    for(int j=0;j<m;j++)
    {
        int k;
        cin>>k;
        b.push_back(k);
    }
    Solution s;
    c=s.intersect(a,b);
    for(int i=0;i<c.size();i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
    return 0;
}
