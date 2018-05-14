#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++)
        {
            reverse(A[i].begin(),A[i].end());
            for(int j=0;j<A[i].size();j++)
            {
                A[i][j]^=1;
            }
        }
        return A;
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
    v=s.flipAndInvertImage(v);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
