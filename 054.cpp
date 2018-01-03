#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        if(m==0)
        {
            return ans;
        }
        int n=matrix[0].size();
        if(n==0)
        {
            return ans;
        }
        int t,l,r,x,y;
        int total=n*m;
        t=l=r=x=y=0;
        r++;
        while(t<total)
        {
            while(y<n)    {ans.push_back(matrix[x][y++]);t++;}   n--,y--,x++;   if(t==total)    break;
            while(x<m)    {ans.push_back(matrix[x++][y]);t++;}   m--,x--,y--;   if(t==total)    break;
            while(y>=l)   {ans.push_back(matrix[x][y--]);t++;}   l++,y++,x--;   if(t==total)    break;
            while(x>=r)   {ans.push_back(matrix[x--][y]);t++;}   r++,x++,y++;   if(t==total)    break;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int m,n;
    cin>>m>>n;
    vector<vector<int> >v(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<int> ans=s.spiralOrder(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
