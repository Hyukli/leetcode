#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<string,int> m;
        int n=s.size();
        if(n<=10)
        {
            return ans;
        }
        string ss=s.substr(0,10);
        m[ss]=1;
        for(int i=10;i<n;i++)
        {
            ss=ss.substr(1);
            ss+=s[i];
            //cout<<ss<<endl;
            if(m.find(ss)==m.end())
            {
                m[ss]=1;
            }
            else if(m[ss]==1)
            {
                ans.push_back(ss);
                m[ss]++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    vector<string> ans=s.findRepeatedDnaSequences(ss);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
