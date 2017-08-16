#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0)
        {
            return ans;
        }
        int m=matrix.size();
        int n=matrix[0].size();
        int t=m*n;
        int flag=0;
        int i=0,j=0;
        while(t--)
        {
            ans.push_back(matrix[i][j]);
            if(!flag)
            {
                if(i-1>=0&&j+1<n)
                {
                    i--;
                    j++;
                }
                else if(j+1<n)
                {
                    j++;
                    flag^=1;
                }
                else
                {
                    i++;
                    flag^=1;
                }
            }
            else
            {
                if(i+1<m&&j-1>=0)
                {
                    i++;
                    j--;
                }
                else if(i+1<m)
                {
                    i++;
                    flag^=1;
                }
                else
                {
                    j++;
                    flag^=1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int m,n;
    cin>>m>>n;
    vector<vector<int> > V;
    vector<int> k;
    for(int i=0;i<m;i++)
    {
        vector<int> v(n);
        for(int j=0;j<m;j++)
        {
            cin>>v[j];
        }
        V.push_back(v);
    }
    k=s.findDiagonalOrder(V);
    for(int i=0;i<k.size();i++)
    {
        cout<<k[i]<<" ";
    }
    cout<<endl;
    return 0;
}
