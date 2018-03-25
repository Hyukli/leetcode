#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        vector<int> v1(n,0);
        vector<int> v2(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                v1[i]=max(v1[i],grid[j][i]);
                v2[i]=max(v2[i],grid[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=(min(v2[i],v1[j])-grid[i][j]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int> (n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<s.maxIncreaseKeepingSkyline(v)<<endl;
    return 0;
}
