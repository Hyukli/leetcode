#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<set<int>> graph(n);
        vector<int> degree(n);
        for(auto e:edges)
        {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        for(int i=0;i<n;i++)
        {
            degree[i]=graph[i].size();
        }
        for(int remain=n;remain>2;)
        {
            vector<int> del;
            for(int i=0;i<n;i++)
            {
                if(degree[i]==1)
                {
                    degree[i]=-1;
                    del.push_back(i);
                    remain--;
                }
            }
            for(auto d:del)
            {
                for(auto neigh:graph[d])
                {
                    degree[neigh]--;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(degree[i]>=0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v(m);
    for(int i=0;i<m;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    vector<int> ans=s.findMinHeightTrees(n,v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
