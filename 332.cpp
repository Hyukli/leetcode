#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto t:tickets)
        {
            m[t.first].insert(t.second);
        }
        visit("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
private:
    map<string,multiset<string>> m;
    vector<string> ans;
    int visit(string s)
    {
        while(m[s].size())
        {
            string tmp=*m[s].begin();
            m[s].erase(m[s].begin());
            visit(tmp);
        }
        ans.push_back(s);
        return 0;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<pair<string,string>> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    vector<string> ans=s.findItinerary(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
