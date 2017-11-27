#include<iostream>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int,vector<int>> m;
        int flag[10004];
        int a[10004];
        memset(a,0,sizeof(a));
        memset(flag,0,sizeof(flag));
        for(auto p:prerequisites)
        {
            int y=p.first;
            int x=p.second;
            a[y]++;
            if(m.find(x)==m.end())
            {
                vector<int> v;
                v.push_back(y);
                m[x]=v;
            }
            else
            {
                m[x].push_back(y);
            }
        }
        int ans=0;
        while(ans<numCourses)
        {
            int k=0;
            for(int i=0;i<numCourses;i++)
            {
                if(flag[i]==0&&a[i]==0)
                {
                    k++;
                    ans++;
                    flag[i]=1;
                    for(int j=0;j<m[i].size();j++)
                    {
                        a[m[i][j]]--;
                    }
                }
            }
            if(k==0)
            {
                return false;
            }
        }
        return true;
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
    cout<<(s.canFinish(n,v)?"Yes":"No")<<endl;;
    return 0;
}
