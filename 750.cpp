#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m-1;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                int tmp=0;
                for(int k=0;k<n;k++)
                {
                    if(grid[i][k]&&grid[j][k])
                    {
                        tmp++;
                    }
                }
                ans+=(tmp*(tmp-1)/2);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<s.countCornerRectangles(v)<<endl;
    return 0;
}
