#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i=0,j=0;i<g.size()&&j<s.size();)
        {
            if(g[i]<=s[j])
            {
                ans++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    int k;
    vector<int> g,s;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        g.push_back(k);
    }
    for(int j=0;j<m;j++)
    {
        cin>>k;
        s.push_back(k);
    }
    Solution ss;
    cout<<ss.findContentChildren(g,s);
    return 0;
}
