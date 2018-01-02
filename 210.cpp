#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        vector<int> ansn;
        int n=numCourses;
        vector<int> v(n,0);
        vector<int> flag(n,0);
        map<int,set<int>> m;
        for(auto p:prerequisites)
        {
            m[p.second].insert(p.first);
            v[p.first]++;
        }
        int t=0;
        int tt;
        for(;t<n;t++)
        {
            tt=0;
            for(int i=0;i<n;i++)
            {
                if(!flag[i]&&v[i]==0)
                {
                    tt=1;
                    flag[i]=1;
                    ans.push_back(i);
                    for(auto k:m[i])
                    {
                        v[k]--;
                    }
                    break;
                }
            }
            if(!tt)
            {
                break;
            }
        }
        if(ans.size()<n)
        {
            return ansn;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> p(m);
    for(int i=0;i<m;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    vector<int> ans=s.findOrder(n,p);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
