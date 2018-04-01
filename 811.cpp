#include<iostream>
#include<vector>
#include<map>
#include<stdio.h>
#include<sstream>
using namespace std;

string to_string(int i)
{
    string s="";
    while(i)
    {
        int t=i%10;
        i/=10;
        char c=t+'0';
        s=c+s;
    }
    return s;
}

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int> m;
        int n=cpdomains.size();
        vector<int> t(n);
        vector<vector<string>> v(n,vector<string>() );
        stringstream ss;
        for(int i=0;i<n;i++)
        {
            string s;
            ss.clear();
            ss.str(cpdomains[i]);
            int k;
            ss>>t[i];
            ss>>s;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='.')
                {
                    v[i].push_back(s.substr(0,j));
                    s=s.substr(j+1);
                    j=-1;
                }

            }
            v[i].push_back(s);
        }
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            int is=v[i].size();
            for(int j=0;j<v[i].size();j++)
            {
                int a=t[i];
                for(int k=i+1;k<n;k++)
                {
                    if(v[k].size()>j)
                    {
                        int ks=v[k].size();
                        int flag=0;
                        for(int p=1;p<=j+1;p++)
                        {
                            if(v[k][ks-p]!=v[i][is-p])
                            {
                                flag=1;
                                break;
                            }
                        }
                        if(!flag)
                        {
                            a+=t[k];
                        }
                    }
                }
                string s=" ";
                for(int f=is-1-j;f<is;f++)
                {
                    s+=v[i][f];
                    s+=".";
                }
                s=s.substr(0,s.size()-1);
                if(m.find(s)==m.end())
                {
                    m[s]=1;
                    s=to_string(a)+s;
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<string> v(n);
    getchar();
    for(int i=0;i<n;i++)
    {
        getline(cin,v[i]);
    }
    vector<string> ans=s.subdomainVisits(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
