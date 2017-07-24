#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        if(strs.size()==0)
        {
            return s;
        }
        s=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            int j;
            if(s.size()>strs[i].size())
            {
                s=s.substr(0,strs[i].size());
            }
            for(j=0;j<s.size();j++)
            {
                if(s[j]!=strs[i][j])
                {
                    s=s.substr(0,j);
                    break;
                }
            }
        }
        return s;
    }
};

int main()
{
    vector<string> v;
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    Solution s;
    cout<<s.longestCommonPrefix(v)<<endl;
    return 0;
}
