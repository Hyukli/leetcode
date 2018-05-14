#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int tmp=0;
                //对应A[I][J]==B[0][0]
                for(int x1=0;x1+i<n;x1++)
                {
                    for(int y1=0;y1+j<n;y1++)
                    {
                        if(A[x1+i][y1+j]==B[x1][y1]&&B[x1][y1]==1)
                        {
                            tmp++;
                        }
                    }
                }
                ans=max(ans,tmp);
                tmp=0;
                //对应B[I][J]==A[0][0]
                for(int x1=0;x1+i<n;x1++)
                {
                    for(int y1=0;y1+j<n;y1++)
                    {
                        if(B[x1+i][y1+j]==A[x1][y1]&&A[x1][y1]==1)
                        {
                            tmp++;
                        }
                    }
                }
                ans=max(ans,tmp);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<vector<int>> v1(n,vector<int> (n));
    vector<vector<int>> v2(n,vector<int> (n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v1[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v2[i][j];
        }
    }
    cout<<s.largestOverlap(v1,v2)<<endl;
    return 0;
}
