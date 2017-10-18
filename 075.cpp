#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i,j;
        int n=nums.size();
        for(i=0,j=n-1;i<j&&i<n&&j>=0;)
        {
            while(nums[i]==0)
            {
                i++;
            }
            while(nums[j]!=0)
            {
                j--;
            }
            if(i<j)
            {
                nums[j]=nums[i];
                nums[i]=0;
                i++;
                j--;
            }
        }
        i=0;
        while(i<n&&nums[i]==0)
        {
            i++;
        }
        for(i,j=n-1;i<j&&i<n&&j>=0;)
        {
            while(nums[i]==1)
            {
                i++;
            }
            while(nums[j]==2)
            {
                j--;
            }
            if(i<j)
            {
                nums[j]=2;
                nums[i]=1;
                i++;
                j--;
            }
        }
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
    s.sortColors(v);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
