#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        for(int i=0;i<1005;i++)
        {
            a[i]=i;
        }
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if(fun(u)!=fun(v))
            {
                a[fun(v)]=fun(u);
            }
            else
            {
                ans=edges[i];
                break;
            }
        }
        return ans;
    }
private:
    int a[1005];
    int fun(int k)
    {
        if(a[k]==k)
        {
            return k;
        }
        return a[k]=fun(a[k]);
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<vector<int> > V;
    for(int i=-0;i<n;i++)
    {
        vector<int> v(2);
        cin>>v[0]>>v[1];
        V.push_back(v);
    }
    vector<int> ans=s.findRedundantConnection(V);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
