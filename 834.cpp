#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<unordered_set<int>> tree(N);
        vector<int> count(N,0);
        vector<int> ans(N,0);
        for(auto e:edges)
        {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        unordered_set<int> s1,s2;
        dfs(0,s1,tree,count,ans);
        dfs2(0,s2,tree,count,ans,N);
        return ans;
    }
private:
    int dfs(int root,unordered_set<int> &s,vector<unordered_set<int>> &tree,vector<int> &count,vector<int> &ans)
    {
        s.insert(root);
        for(auto t:tree[root])
        {
            if(s.count(t)==0)
            {
                dfs(t,s,tree,count,ans);
                count[root]+=count[t];
                ans[root]+=(ans[t]+count[t]);
            }
        }
        count[root]++;
        return 0;
    }

    int dfs2(int root,unordered_set<int> &s,vector<unordered_set<int>> &tree,vector<int> &count,vector<int> &ans,int N)
    {
        s.insert(root);
        for(auto t:tree[root])
        {
            if(s.count(t)==0)
            {
                ans[t]=ans[root]-2*count[t]+N;
                dfs2(t,s,tree,count,ans,N);
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<vector<int>> v(n-1,vector<int> (2));
    for(int i=0;i<n-1;i++)
    {
        cin>>v[i][0]>>v[i][1];
    }
    vector<int> ans=s.sumOfDistancesInTree(n,v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
