#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        map<string,int> m;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        vector<int> flag(S.size(),0);
        for(int i=0;i<S.size();i++)
        {
            for(int j=1;i+j<=S.size();j++)
            {
                string s=S.substr(i,j);
                if(m.find(s)!=m.end())
                {
                    for(int k=i;k<i+j;k++)
                    {
                        flag[k]=1;
                    }
                }
            }
        }
        int t=0;
        vector<string> v(S.size());
        for(int i=0;i<S.size();i++)
        {
            v[i]="";
            char c=S[i];
            v[i]+=c;
        }
        for(int i=0;i<S.size();i++)
        {
            if(t==0)
            {
                if(flag[i]==1)
                {
                    v[i]="<b>"+v[i];
                    t=1;
                }
            }
            else
            {
                if(flag[i]==0)
                {
                    v[i]="</b>"+v[i];
                    t=0;
                }
            }
        }
        if(t==1)
        {
            v[v.size()-1]+="</b>";
        }
        string ans="";
        for(int i=0;i<S.size();i++)
        {
            ans+=v[i];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<string> S(n);
    string ss;
    for(int i=0;i<n;i++)
    {
        cin>>S[i];
    }
    cin>>ss;
    cout<<s.boldWords(S,ss)<<endl;
    return 0;
}
