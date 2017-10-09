#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++)
        {
            tran(i,matrix,n);
        }
    }
private:
    int tran(int i,vector<vector<int>>& m,int n)
    {
        int flag=1;
        for(int j=0;j<3;j++)
        {
            if(flag)
            {
                for(int k=i+1;k<n-i;k++)
                {
                    m[i][k]^=m[n-k-1][i];
                }
            }
            else
            {
                for(int k=i+1;k<n-i;k++)
                {
                    m[n-k-1][i]^=m[i][k];
                }
            }
            flag^=1;
        }
        flag=1;
        for(int j=0;j<3;j++)
        {
            if(flag)
            {
                for(int k=i+1;k<n-i;k++)
                {
                    m[k][n-1-i]^=m[n-k-1][i];
                }
            }
            else
            {
                for(int k=i+1;k<n-i;k++)
                {
                    m[n-k-1][i]^=m[k][n-1-i];
                }
            }
            flag^=1;
        }

        flag=1;
        for(int j=0;j<3;j++)
        {
            if(flag)
            {
                for(int k=i+1;k<n-i;k++)
                {
                    m[n-1-i][n-1-k]^=m[n-k-1][i];
                }
            }
            else
            {
                for(int k=i+1;k<n-i;k++)
                {
                    m[n-k-1][i]^=m[n-1-i][n-1-k];
                }
            }
            flag^=1;
        }
        return 0;
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
    s.rotate(v);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
