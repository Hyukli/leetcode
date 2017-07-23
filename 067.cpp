#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string s="";
        int mark=0;
        for(int i=0;i<a.size()||i<b.size();i++)
        {
            if(i>=a.size())
            {
                a+='0';
            }
            if(i>=b.size())
            {
                b+='0';
            }
        }
        for(int i=0;i<a.size()&&i<b.size();i++)
        {
            char c=mark+a[i]+b[i]-'0';
            if(c>'1')
            {
                c-=2;
                mark=1;
            }
            else
            {
                mark=0;
            }
            s+=c;
        }
        if(mark==1)
        {
            s+='1';
        }
        reverse(s.begin(),s.end());
        return s;
    }
};

int main()
{
    Solution s;
    string s1,s2;
    cin>>s1>>s2;
    cout<<s.addBinary(s1,s2)<<endl;
    return 0;
}
