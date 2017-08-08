#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        init();
        int ans=0;
        for(int i=0;i<M.size();i++)
        {
            for(int j=0;j<M.size()&&i!=j;j++)
            {
                if(M[i][j]==1)
                {
                    a[bcj(i)]=bcj(j);
                }
            }
        }
        for(int i=0;i<M.size();i++)
        {
            if(a[i]==i)
            {
                ans++;
            }
        }
        return ans;
    }
private:
    int a[202];
    int init()
    {
        for(int i=0;i<202;i++)
        {
            a[i]=i;
        }
        return 0;
    }
    int bcj(int j)
    {
        if(a[j]==j)
        {
            return j;
        }
        else
        {
            return a[j]=bcj(a[j]);
        }
    }
};

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > V(n);
    for(int i=0;i<n;i++)
    {
        vector<int>v(n);
        for(int j=0;j<n;j++)
        {
            cin>>v[j];
        }
        V[i]=v;
    }
    Solution s;
    cout<<s.findCircleNum(V)<<endl;
    return 0;
}
