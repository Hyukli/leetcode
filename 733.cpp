#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m=image.size();
        n=image[0].size();
        int k=image[sr][sc];
        if(k==newColor)
        {
            return image;
        }
        dfs(image,sr,sc,k,newColor);
        return image;
    }
private:
    int m,n;
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int dfs(vector<vector<int>>& image,int i,int j,int k,int newc)
    {
        image[i][j]=newc;
        for(int ii=0;ii<4;ii++)
        {
            int dx=i+x[ii];
            int dy=j+y[ii];
            //cout<<"$$"<<endl;
            if(dx>=0&&dx<m&&dy>=0&&dy<n&&image[dx][dy]==k)
            {
                dfs(image,dx,dy,k,newc);
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int m,n,sr,sc,newc;
    cin>>m>>n>>sr>>sc>>newc;
    vector<vector<int>> v(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    s.floodFill(v,sr,sc,newc);
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
