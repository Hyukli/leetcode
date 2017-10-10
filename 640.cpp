#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

struct Node
{
    string ss;
    bool f;
};

int stoi(string s)
{
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans*=10;
        ans+=s[i]-'0';
    }
    return ans;
}

string to_string(int i)
{
    string ans="";
    while(i)
    {
        char c=(i%10)+'0';
        ans=c+ans;
        i/=10;
    }
    return ans;
}

class Solution {
public:
    string solveEquation(string equation) {
        string s=equation;
        if(s[0]!='-')
        {
            s='+'+s;
        }
        int dh=s.find('=');
        vector<Node> left;
        int t=1;
        for(int i=1;i<=dh;i++)
        {
            if(s[i]=='+'||s[i]=='='||s[i]=='-')
            {
                Node node;
                node.ss=s.substr(t,i-t);
                left.push_back(node);
                t=i+1;
            }
        }
        t=0;
        for(int i=0;i<dh;i++)
        {
            if(s[i]=='+')
            {
                left[t++].f=1;
            }
            else if(s[i]=='-')
            {
                left[t++].f=0;
            }
        }
        int tt=t;
        s=s.substr(dh+1);
        s+='+';
        if(s[0]!='-')
        {
            s='+'+s;
        }
        t=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='+'||s[i]=='='||s[i]=='-')
            {
                Node node;
                node.ss=s.substr(t,i-t);
                left.push_back(node);
                t=i+1;
            }
        }
        t=tt;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='-')
            {
                left[t++].f=1;
            }
            else if(s[i]=='+')
            {
                left[t++].f=0;
            }
        }
        int sum=0;
        int xsum=0;
        for(auto x:left)
        {
            if(x.ss[x.ss.size()-1]!='x')
            {
                //cout<<x.ss<<endl;
                if(x.f==1)
                {
                    sum+=stoi(x.ss);
                }
                else
                {
                    sum-=stoi(x.ss);
                }
                //cout<<x.ss<<endl;
            }
            else
            {
                string st=x.ss.substr(0,x.ss.size()-1);
                if(st=="")
                {
                    st="1";
                }
                //cout<<st<<endl;
                if(x.f==1)
                {
                    xsum-=stoi(st);
                }
                else
                {
                    xsum+=stoi(st);
                }
                //cout<<st<<endl;
            }
        }
        if(xsum==0)
        {
            if(sum==0)
            {
                return "Infinite solutions";
            }
            else
            {
                return "No solution";
            }
        }
        string ans="x=";
        int an=sum/xsum;
        ans+=to_string(an);
        return ans;
    }
};

int main()
{
    string ss;
    Solution s;
    cin>>ss;
    cout<<s.solveEquation(ss)<<endl;
    return 0;
}
