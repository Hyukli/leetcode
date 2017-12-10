#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> v(N+1,vector<int> (N+1,700000));
        vector<bool> used(N+1,0);
        vector<int> d(N+1,700000);
        for(int i=0;i<times.size();i++)
        {
            v[times[i][0]][times[i][1]]=min(v[times[i][0]][times[i][1]],times[i][2]);
        }
        d[K]=0;
        while(true)
        {
            int vv=-1;
            for(int u=1;u<=N;u++)
            {
                if(!used[u]&&(vv==-1||d[u]<d[vv]))
                {
                    vv=u;
                }
            }
            if(vv==-1)
            {
                break;
            }
            used[vv]=true;
            for(int u=1;u<=N;u++)
            {
                d[u]=min(d[u],d[vv]+v[vv][u]);
            }
        }
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            //cout<<d[i]<<endl;
            ans=max(ans,d[i]);
        }
        if(ans==700000)
        {
            return -1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    int t;
    cin>>t;
    vector<vector<int> >v(t,vector<int> (3));
    for(int i=0;i<t;i++)
    {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    cout<<s.networkDelayTime(v,n,k)<<endl;
    return 0;
}
