#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0)
        {
            return 0;
        }
        int n=matrix[0].size();
        int i=0,j=n-1;
        while(i<m&&j>=0)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            if(matrix[i][j]<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int m,n,t;
    cin>>m>>n>>t;
    vector<vector<int>> v(m,vector<int> (m));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<(s.searchMatrix(v,t)?"Yes":"No")<<endl;
    return 0;
}
