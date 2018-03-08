#include<iostream>
#include<vector>
using namespace std;

class Solution {
    vector<int> v;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        for(int i=0;i<400;i++)
        {
            v.push_back(i);
        }
        int n=graph.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                //cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" "<<v[200]<<" "<<v[201]<<" "<<v[202]<<" "<<v[203]<<endl;
                if(findroot(graph[i][j])==findroot(i))
                {
                    return false;
                }
                else
                {
                    merge(graph[i][j],i+200);
                    merge(graph[i][j]+200,i);
                }
            }
        }
        return true;
    }
private:
    int findroot(int i)
    {
        if(i==v[i])
        {
            return i;
        }
        return findroot(v[i]);
    }
    int merge(int i,int j)
    {
        i=findroot(i);
        j=findroot(j);
        v[j]=i;
        return 0;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int k;
            cin>>k;
            v[i].push_back(k);
        }
    }
    cout<<(s.isBipartite(v)?"Yes":"No")<<endl;
    return 0;
}
