#include<iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<t.size();j++)
            {
                if(s[i]==t[j])
                {
                    t[j]+=26;
                    break;
                }
            }
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]>='a'&&t[i]<='z')
            {
                return t[i];
            }
        }
    }
};

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    Solution s;
    cout<<s.findTheDifference(s1,s2)<<endl;
    return 0;
}
