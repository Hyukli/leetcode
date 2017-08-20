#include<iostream>
#include<vector>

using namespace std;

int vy[]={-1,-1,0,1,1,1,0,-1,0};
int vx[]={0,1,1,1,0,-1,-1,-1,0};

class Solution {
public:
    vector<vector<int> > imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> V;
        for(int i=0;i<M.size();i++)
        {
            vector<int> v(M[0].size());
            V.push_back(v);
        }
        for(int i=0;i<M.size();i++)
        {
            for(int j=0;j<M[i].size();j++)
            {
                int n=0,sum=0;
                for(int k=0;k<9;k++)
                {
                    int x=i+vx[k];
                    int y=j+vy[k];
                    if(x>=0&&x<M.size()&&y>=0&&y<M[i].size())
                    {
                        n++;
                        sum+=M[x][y];
                    }
                }
                V[i][j]=sum/n;
            }
        }
        return V;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> V;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        vector<int> v(m);
        for(int j=0;j<m;j++)
        {
            cin>>v[j];
        }
        V.push_back(v);
    }
    vector<vector<int>> ans;
    ans=s.imageSmoother(V);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
