#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int expressiveWords(string S, vector<string>& words)
    {
        int ans=0;
        if(S.size()==0)
        {
            for(int i=0; i<words.size(); i++)
            {
                if(words[i].size()==0)
                {
                    ans++;
                }
            }
            return ans;
        }
        vector<char> cc;
        vector<int> v;
        int tmp=1;
        char c=S[0];
        for(int i=1; i<S.size(); i++)
        {
            if(S[i]==c)
            {
                tmp++;
            }
            else
            {
                cc.push_back(c);
                v.push_back(tmp);
                c=S[i];
                tmp=1;
            }
        }
        cc.push_back(c);
        v.push_back(tmp);
        for(int i=0; i<words.size(); i++)
        {
            string s=words[i];
            if(s.size()==0)
            {
                break;
            }
            else
            {
                vector<char> ccc;
                vector<int> vv;
                int ttmp=1;
                char ac=s[0];
                for(int k=1; k<s.size(); k++)
                {
                    if(s[k]==ac)
                    {
                        ttmp++;
                    }
                    else
                    {
                        ccc.push_back(ac);
                        vv.push_back(ttmp);
                        ac=s[k];
                        ttmp=1;
                    }
                }
                ccc.push_back(ac);
                vv.push_back(ttmp);
                int flag=0;
                if(ccc.size()==cc.size())
                {
                    for(int j=0; j<cc.size(); j++)
                    {
                        if(ccc[j]==cc[j]&&v[j]==vv[j]||(v[j]>vv[j]&&v[j]>=3))
                        {
                        }
                        else
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        ans++;
                    }
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
    string S;
    cin>>S>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    cout<<s.expressiveWords(S,v)<<endl;
    return 0;
}
