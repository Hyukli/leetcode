#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0)
        {
            return ;
        }
        int c=-1;
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            int flag=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                c=i;
                for(int ii=0;ii<n;ii++)
                {
                    for(int jj=0;jj<m;jj++)
                    {
                        if(matrix[jj][ii]==0)
                        {
                            matrix[i][ii]=0;
                            break;
                        }
                    }
                }
                break;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(i!=c)
            {
                int flag=0;
                for(int j=0;j<n;j++)
                {
                    if(!matrix[i][j])
                    {
                        flag++;
                        break;
                    }
                }
                if(flag)
                {
                    for(int j=0;j<n;j++)
                    {
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(c>-1)
        {
            for(int i=0;i<n;i++)
            {
                if(matrix[c][i]==0)
                {
                    for(int j=0;j<m;j++)
                    {
                        matrix[j][i]=0;
                    }
                }
            }
        }
        return ;
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
    s.setZeroes(v);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
