#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0)    return false;
        int m=matrix[0].size();
        if(m==0)    return false;
        int l=0,r=m*n-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(matrix[mid/m][mid%m]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return matrix[r/m][r%m]==target;
    }
};

int main()
{
    Solution s;
    int n,m,t;
    cin>>n>>m>>t;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<(s.searchMatrix(v,t)?"Yes":"No")<<endl;
    return 0;
}
