#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        for(int i=0;i<indexes.size();i++)
        {
            int flag=0;
            for(int j=0;j<sources[i].size();j++)
            {
                if(S.size()<=indexes[i]+j||S[indexes[i]+j]!=sources[i][j])
                {
                    cout<<S.size()<<" "<<indexes[i]+j<<endl;
                    flag++;
                    break;
                }
            }
            if(!flag)
            {
                string s1=S.substr(0,indexes[i]);
                string s2=S.substr(indexes[i]+sources[i].size());
                S=s1+targets[i]+s2;
                for(int j=i;j<indexes.size();j++)
                {
                    if(indexes[j]>indexes[i])
                    {
                        indexes[j]+=(targets[i].size()-sources[i].size());
                    }
                }
            }
        }
        return S;
    }
};

int main()
{
    Solution s;
    string S;
    int n;
    cin>>n>>S;
    vector<int> in(n);
    vector<string> so(n);
    vector<string> ta(n);
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>so[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>ta[i];
    }
    cout<<s.findReplaceString(S,in,so,ta)<<endl;
    return 0;
}
