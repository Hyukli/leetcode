#include<iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j;
        for(i=0,j=0;i<t.size()&&j<s.size();i++)
        {
            if(s[j]==t[i])
            {
                j++;
            }
        }
        if(j>=s.size())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution ss;
    string s,t;
    cin>>s>>t;
    cout<<(ss.isSubsequence(s,t)?"Yes":"No")<<endl;
    return 0;
}
