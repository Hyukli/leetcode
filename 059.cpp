#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> V(n,vector<int>(n));
        if(n==0)
        {
            return V;
        }
        int k=1,i=0,j=0;
        V[0][0]=1;
        while(k<n*n)
        {
            while(j+1< n&&!V[i][j+1]) V[i][++j]=++k;
            while(i+1< n&&!V[i+1][j]) V[++i][j]=++k;
            while(j-1>=0&&!V[i][j-1]) V[i][--j]=++k;
            while(i-1>=0&&!V[i-1][j]) V[--i][j]=++k;
        }
        return V;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<vector<int>> v=s.generateMatrix(n);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
