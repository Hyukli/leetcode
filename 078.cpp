#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> V;
        int n=nums.size();
        for(int i=0;i<pow(2,n);i++)
        {
            vector<int> v;
            int t=1;
            for(int j=0;j<n;j++)
            {
                //cout<<i<<" "<<t<<endl;
                if(i&t)
                {
                    v.push_back(nums[j]);
                }
                t<<=1;
            }
            V.push_back(v);
        }
        return V;
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
    vector<vector<int>> ans=s.subsets(v);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
