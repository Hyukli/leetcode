#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

struct Node
{
    string s;
    int t;
};

bool fun(string s1,string s2)
{
    for(int i=0;i<s1.size()&&1<s2.size();i++)
    {
        if(s1[i]<s2[i])
        {
            return true;
        }
        else if(s1[i]>s2[i])
        {
            return false;
        }
    }
    if(s1.size()>s2.size())
    {
        return false;
    }
    return true;
}

bool cmp(const Node& a,const Node& b)
{
    if(a.t!=b.t)
    {
        return a.t>b.t;
    }
    return fun(a.s,b.s);
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        vector<Node> v;
        for(auto mm:m)
        {
            Node n;
            n.s=mm.first;
            n.t=mm.second;
            v.push_back(n);
        }
        sort(v.begin(),v.end(),cmp);
        vector<string> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].s);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<string> ans=s.topKFrequent(v,k);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
