#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<m-2;j++)
            {
                if(isM(grid,i,j))   ans++;
            }
        }
        return ans;
    }
private:
    bool isM(vector<vector<int>> &v,int i,int j)
    {
        vector<int> flag(9,0);
        for(int d=0;d<3;d++)
        {
            for(int f=0;f<3;f++)
            {
                if(v[i+d][j+f]<1||v[i+d][j+f]>9)    return false;
                flag[v[i+d][j+f]-1]=1;
            }
        }
        for(int i=0;i<9;i++)
        {
            if(flag[i]==0) return false;
        }
        int k=v[i][j]+v[i+1][j]+v[i+2][j];
        for(int d=0;d<3;d++)
        {
            if(k!=v[i+d][j]+v[i+d][j+1]+v[i+d][j+2])    return false;
            if(k!=v[i][j+d]+v[i+1][j+d]+v[i+2][j+d])     return false;
        }
        if(k!=v[i][j]+v[i+1][j+1]+v[i+2][j+2])  return false;
        if(k!=v[i][j+2]+v[i+1][j+1]+v[i+2][j])  return false;
        return true;
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
    cout<<s.numMagicSquaresInside(v)<<endl;
    return 0;
}
