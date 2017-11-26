#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        map<string,vector<string>> m;
        if(words1.size()!=words2.size())
        {
            return false;
        }
        for(int i=0;i<pairs.size();i++)
        {
            string s1=pairs[i].first;
            string s2=pairs[i].second;
            if(m.find(s1)==m.end())
            {
                vector<string> v;
                v.push_back(s2);
                m[s1]=v;
            }
            else
            {
                m[s1].push_back(s2);
            }
            if(m.find(s2)==m.end())
            {
                vector<string> v;
                v.push_back(s1);
                m[s2]=v;
            }
            else
            {
                m[s2].push_back(s1);
            }
        }
        for(int i=0;i<words1.size();i++)
        {
            string s1=words1[i];
            string s2=words2[i];
            if(s1==s2)
            {
                continue;
            }
            if(m.find(s1)==m.end())
            {
                return false;
            }
            int flag=0;
            for(int j=0;j<m[s1].size();j++)
            {
                //cout<<m[s1][j]<<" "<<s2<<endl;
                if(m[s1][j]==s2)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
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
    vector<string> v1(n),v2(n);
    vector<pair<string,string>> p(m);
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>v2[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    cout<<(s.areSentencesSimilar(v1,v2,p)?"Yes":"No")<<endl;
    return 0;
}
