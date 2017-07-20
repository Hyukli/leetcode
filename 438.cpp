#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string t)
    {
        vector<int> v;
        if(s.size()==0||t.size()==0)
        {
            return v;
        }
        int has[256];
        int mark[256];
        memset(has,0,sizeof(has));
        memset(mark,0,sizeof(mark));
        int ss=s.size();
        int ts=t.size();
        for(int i=0; i<ts; i++)
        {
            has[t[i]]++;
        }
        for(int i=0; i<ts; i++)
        {
            mark[s[i]]++;
        }
        int flag;
        for(int i=0; i+ts<=ss; i++)
        {
            flag=0;
            for(int j=0; j<256; j++)
            {
                if(has[j]!=mark[j])
                {
                    flag++;
                    break;
                }
            }
            if(flag==0)
            {
                v.push_back(i);
            }
            mark[s[i]]--;
            mark[s[i+ts]]++;
        }
        return v;
    }
};

int main()
{
    string s,t;
    vector<int> v;
    cin>>s>>t;
    Solution ss;
    v=ss.findAnagrams(s,t);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
