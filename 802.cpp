#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> v(n);
        vector<int> len(n,0);
        for(int i=0;i<n;i++)
        {
            len[i]=graph[i].size();
            for(int j=0;j<graph[i].size();j++)
            {
                v[graph[i][j]].push_back(i);
            }
        }
        vector<int> ans;
        vector<int> mark(n,0);
        while(1)
        {
            int flag=0;
            for(int i=0;i<n;i++)
            {
                if(!mark[i]&&len[i]==0)
                {
                    flag=1;
                    mark[i]=1;
                    ans.push_back(i);
                    for(int j=0;j<v[i].size();j++)
                    {
                        len[v[i][j]]--;
                    }
                }
            }
            if(flag==0)
            {
                break;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        vector<int> tmp(k);
        v.push_back(tmp);
        for(int j=0;j<k;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<int> ans=s.eventualSafeNodes(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
