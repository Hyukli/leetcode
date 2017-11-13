#include<iostream>
#include<vector>
#include<map>
using namespace std;

string to_string(int t)
{
    string ans="";
    while(t)
    {
        char c=t%10+'0';
        ans=c+ans;
        t/=10;
    }
    return ans;
}

class Solution {
public:
    string countOfAtoms(string formula) {
        for(int i=1;i<formula.size();i++)
        {
            if(iscc(formula[i])&&isc(formula[i-1]))
            {
                string s1=formula.substr(0,i);
                string s2=formula.substr(i);
                formula=s1+"1"+s2;
            }
        }
        if(formula[formula.size()-1]<'0'||formula[formula.size()-1]>'9')
        {
            formula+="1";
        }
        int t=0;
        for(int i=0;i<formula.size();i++)
        {
            if(formula[i]=='(')
            {
                t=i;
            }
            if(formula[i]==')')
            {
                string st=formula.substr(i+1);
                string s1=formula.substr(0,t);
                string sd=formula.substr(t+1,i-t-1);
                int k;
                for(k=i+1;k<formula.size();k++)
                {
                    if(formula[k]>'9'||formula[k]<'0')
                    {
                        break;
                    }
                }
                string s2=formula.substr(k);
                int t=getn(st);
                sd=fun(sd,t);
                formula=s1+sd+s2;
                i=-1;
            }
        }
        map<string,int> mm;
        string stmp="";
        int flag=0;
        int k=0;
        for(int i=0;i<formula.size();i++)
        {
            if(!flag)
            {
                if(formula[i]<'0'||formula[i]>'9')
                {
                    stmp+=formula[i];
                }
                else
                {
                    k+=(formula[i]-'0');
                    flag=1;
                }
            }
            else
            {
                if(formula[i]>='0'&&formula[i]<='9')
                {
                    k*=10;
                    k+=(formula[i]-'0');
                }
                else
                {
                    mm[stmp]+=k;
                    flag=0;
                    stmp="";
                    stmp+=formula[i];
                    k=0;
                }
            }
        }
        mm[stmp]+=k;
        string ans="";
        for(auto mi:mm)
        {
            ans+=mi.first;
            if(mi.second!=1)
            {
                ans+=to_string(mi.second);
            }
        }
        return ans;
    }
private:
    string f(int i)
    {
        string s="";
        while(i)
        {
            char c=i%10+'0';
            s=c+s;
            i/=10;
        }
        return s;
    }



    bool isc(char c)
    {
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        {
            return true;
        }
        return false;
    }

    bool iscc(char c)
    {
        if(c>='A'&&c<='Z'||c=='('||c==')')
        {
            return true;
        }
        return false;
    }

    int getn(string s)
    {
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>'9'||s[i]<'0')
            {
                return sum;
            }
            else
            {
                sum*=10;
                sum+=s[i]-'0';
            }
        }
        return sum;
    }
    string fun(string s,int t)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                string ss=s.substr(i);
                int tt=getn(ss);
                int k;
                for(k=i+1;k<s.size();k++)
                {
                    if(s[k]>'9'||s[k]<'0')
                    {
                        break;
                    }
                }
                string s1=s.substr(0,i);
                string s2=s.substr(k);
                string s3=f(tt*t);
                s=s1+s3;
                i=s.size();
                s=s+s2;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.countOfAtoms(ss)<<endl;
    return 0;
}
