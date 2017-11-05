#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        vector<vector<string>> v(33);
        for(int i=0;i<words.size();i++)
        {
            int n=words[i].size();
            v[n].push_back(words[i]);
        }
        vector<vector<string>> v2(33);
        v2[1]=v[1];
        int i,j,k;
        if(v[1].size()==0)
        {
            return "";
        }
        for(i=1;i<33;i++)
        {
            if(v2[i].size()==0)
            {
                break;
            }
            for(j=0;j<v[i+1].size();j++)
            {
                string s=v[i+1][j];
                int sl=s.size();
                s=s.substr(0,sl-1);
                for(k=0;k<v2[i].size();k++)
                {
                    if(v2[i][k]==s)
                    {
                        v2[i+1].push_back(v[i+1][j]);
                    }
                }
            }
        }
        if(i<2)
        {
            return "";
        }
        sort(v2[i-1].begin(),v2[i-1].end());
        return v2[i-1][0];
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.longestWord(v)<<endl;
    return 0;
}
