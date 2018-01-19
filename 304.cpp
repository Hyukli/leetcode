#include<iostream>
#include<vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        m=matrix.size();
        if(m!=0)
        {
            n=matrix[0].size();
            v=vector<vector<int>> (m+1,vector<int> (n+1,0));
            for(int i=0;i<m+1;i++)
            {
                v[i][0]=0;
            }
            for(int i=0;i<n+1;i++)
            {
                v[0][i]=0;
            }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    v[i+1][j+1]=matrix[i][j]+v[i][j+1]+v[i+1][j]-v[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(m==0||n==0)
        {
            return 0;
        }
        return v[row2+1][col2+1]-v[row1][col2+1]-v[row2+1][col1]+v[row1][col1];
    }
private:
    int m,n;
    vector<vector<int>> v;
};

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    NumMatrix obj = NumMatrix(v);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<obj.sumRegion(a,b,c,d)<<endl;
    return 0;
}
