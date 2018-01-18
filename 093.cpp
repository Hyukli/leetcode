#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

int stoi(string s)
{
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans*=10;
        ans+=(s[i]-'0');
    }
    return ans;
}

string to_string(int n)
{
    if(n==0)
    {
        return "0";
    }
    string s="";
    while(n!=0)
    {
        char c=n%10+'0';
        s=c+s;
        n/=10;
    }
    return s;
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string tmp;
        for(int a=1;a<=3;a++)
        {
            for(int b=1;b<=3;b++)
            {
                for(int c=1;c<=3;c++)
                {
                    for(int d=1;d<=3;d++)
                    {
                        if(a+b+c+d==s.size())
                        {
                            int A=stoi(s.substr(0,a));
                            int B=stoi(s.substr(a,b));
                            int C=stoi(s.substr(a+b,c));
                            int D=stoi(s.substr(a+b+c,d));
                            if(A<=255&&B<=255&&C<=255&&D<=255)
                            {
                                if((tmp=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length()==s.size()+3)
                                {
                                    ans.push_back(tmp);
                                }
                            }
                        }
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
    string ss;
    cin>>ss;
    vector<string> v=s.restoreIpAddresses(ss);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}
