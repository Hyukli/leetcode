#include<iostream>
#include<vector>
using namespace std;

class Solution {

int htot(string s)
{
    int ans=0;
    if(s[0]>='0'&&s[0]<='9')
    {
        ans+=16*(s[0]-'0');
    }
    else
    {
        ans+=16*(10+(s[0]-'a'));
    }
    if(s[1]>='0'&&s[1]<='9')
    {
        ans+=s[1]-'0';
    }
    else
    {
        ans+=(10+(s[1]-'a'));
    }
    return ans;
}

public:
    string similarRGB(string color) {
    string s=color;
    char c1,c2,c3;
    int r,g,b;
    r=htot(s.substr(1,2));
    g=htot(s.substr(3,2));
    b=htot(s.substr(5,2));
    //cout<<r<<" "<<g<<" "<<b<<endl;
    int r1=r/17;
    if(r-r1*17>r1*17+17-r)
    {
        r1++;
    }

    int g1=g/17;
    if(g-g1*17>g1*17+17-g)
    {
        g1++;
    }
    int b1=b/17;
    if(b-b1*17>b1*17+17-b)
    {
        b1++;
    }
    string ans="#";
    if(r1<10)
    {
        char c=r1+'0';
        ans+=c;
        ans+=c;
    }
    else
    {
        char c='a'+(r1-10);
        ans+=c;
        ans+=c;
    }
    if(g1<10)
    {
        char c=g1+'0';
        ans+=c;
        ans+=c;
    }
    else
    {
        char c='a'+(g1-10);
        ans+=c;
        ans+=c;
    }
    if(b1<10)
    {
        char c=b1+'0';
        ans+=c;
        ans+=c;
    }
    else
    {
        char c='a'+(b1-10);
        ans+=c;
        ans+=c;
    }
    //cout<<ans<<endl;
    return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.similarRGB(ss)<<endl;
    return 0;
}
