#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n=bottom.size();
        map<string,set<char>> m;
        for(int i=0;i<allowed.size();i++)
        {
            string s=allowed[i].substr(0,2);
            m[s].insert(allowed[i][2]);
        }
        vector<vector<set<char>>> dp(n,vector<set<char>>(n));
        for(int i=0;i<n;i++)
        {
            dp[0][i].insert(bottom[i]);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                for(auto c1:dp[i-1][j])
                {
                    for(auto c2:dp[i-1][j+1])
                    {
                        string s="";
                        s=s+c1+c2;
                        for(auto c:m[s])
                        {
                            dp[i][j].insert(c);
                        }
                    }
                }
            }
        }
        return !dp[n-1][0].empty();
    }
};

int main()
{
    Solution s;
    string b;
    int n;
    cin>>b>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<(s.pyramidTransition(b,v)?"Yes":"No")<<endl;
    return 0;
}
