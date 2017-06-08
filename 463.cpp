#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid[0].size();i++)
        {
            if(grid[0][i])
            {
                ans++;
            }
        }
        for(int i=1;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if((grid[i-1][j])!=(grid[i][j]))
                {
                    ans++;
                }
            }
        }
        for(int i=0;i<grid[0].size();i++)
        {
            if(grid[grid.size()-1][i])
            {
                ans++;
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][0])
            {
                ans++;
            }
        }
        for(int i=1;i<grid[0].size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if((grid[j][i-1])!=(grid[j][i]))
                {
                    ans++;
                }
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][grid[0].size()-1])
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int > >vv;
    while(n--)
    {
        vector<int> v;
        for(int i=0;i<m;i++)
        {
            int k;
            cin>>k;
            v.push_back(k);
        }
        vv.push_back(v);
    }
    Solution s;
    cout<<s.islandPerimeter(vv)<<endl;
    return 0;
}
