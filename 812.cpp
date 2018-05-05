#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans=0;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int x1,x2,x3,y1,y2,y3;
                    x1=points[i][0];
                    y1=points[i][1];
                    x2=points[j][0];
                    y2=points[j][1];
                    x3=points[k][0];
                    y3=points[k][1];
                    double tmp=abs(0.5*(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2));
                    ans=max(ans,tmp);
                }
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
    vector<vector<int>> v(n,vector<int> (2));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<s.largestTriangleArea(v)<<endl;
    return 0;
}
