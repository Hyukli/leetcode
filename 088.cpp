#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0&&j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k--]=nums1[i--];
            }
            else
            {
                nums1[k--]=nums2[j--];
            }
        }
        while(j>=0)
        {
            nums1[k--]=nums2[j--];
        }
    }
};

int main()
{
    vector<int> nums1,nums2;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n+m;i++)
    {
        nums1.push_back(0);
    }
    for(int i=0;i<n;i++)
    {
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++)
    {
        //cin>>nums2[i];
        int k;
        cin>>k;
        nums2.push_back(k);
    }
    Solution s;
    s.merge(nums1,n,nums2,m);
    for(int i=0;i<m+n;i++)
    {
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
    return 0;
}
