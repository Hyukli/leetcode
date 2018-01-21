#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> tmp(n,0);
        for(int i=0;i<n;i++)
        {
            tmp[i]=matrix[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]!=tmp[j-1])
                {
                    return false;
                }
            }
            tmp.pop_back();
            tmp.insert(tmp.begin(),matrix[i][0]);
        }
        return true;
    }
};

int main()
{
    Solution s;
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<(s.isToeplitzMatrix(v)?"Yes":"No")<<endl;
    return 0;
}
