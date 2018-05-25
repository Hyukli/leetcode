#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        int n=0;
        int m=0;
        for(int i=0;i<IP.size();i++)
        {
            if(IP[i]=='.')  n++;
            if(IP[i]==':')  m++;
        }
        if(n==3)
        {
            int flag=0;
            IP+=".";
            string tmp="";
            for(int i=0;i<IP.size();i++)
            {
                if(IP[i]!='.')
                {
                    tmp+=IP[i];
                }
                else
                {
                    if(!judge(tmp))
                    {
                        flag=1;
                        break;
                    }
                    else
                    {
                        tmp="";
                    }
                }
            }
            if(!flag)   return "IPv4";
        }
        if(m==7)
        {
            int flag=0;
            IP+=":";
            string tmp="";
            for(int i=0;i<IP.size();i++)
            {
                if(IP[i]!=':')
                {
                    tmp+=IP[i];
                }
                else
                {
                    if(!judge2(tmp))
                    {
                        flag=1;
                        break;
                    }
                    else
                    {
                        tmp="";
                    }
                }
            }
            if(!flag)   return "IPv6";
        }
        return "Neither";
    }
private:
    bool judge(string s)
    {
        if(s.size()==0||s.size()>1&&s[0]=='0')    return false;
        int tmp=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>'9'||s[i]<'0')  return false;
            tmp*=10;
            tmp+=s[i]-'0';
        }
        if(tmp>=0&&tmp<=255)    return true;
        return false;
    }

    bool judge2(string s)
    {
        if(s.size()==0||s.size()>4)    return false;
        for(int i=0;i<s.size();i++)
        {
            if(!(s[i]<='9'&&s[i]>='0'||s[i]>='a'&&s[i]<='f'||s[i]>='A'&&s[i]<='F'))  return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string s1;
    cin>>s1;
    cout<<s.validIPAddress(s1)<<endl;
    return 0;
}
