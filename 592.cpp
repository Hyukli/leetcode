#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        string ans="";
        if(expression.size()==0)
        {
            return ans;
        }
        vector<char> fuhao;
        vector<int> fenzi;
        vector<int> fenmu;
        if(expression[0]!='-')
        {
            expression='+'+expression;
        }
        int a,b;
        char c,xian;
        while(expression!="")
        {
            stringstream s;
            string tmp;
            s<<expression;
            s>>c>>a>>xian>>b;
            s>>tmp;
            fuhao.push_back(c);
            fenzi.push_back(a);
            fenmu.push_back(b);
            expression=tmp;
        }
        int fm=fun(fenmu);
        int fz=fun2(fuhao,fenzi,fenmu,fm);
        if(fz==0)
        {
            return "0/1";
        }
        int tmp=gcd(fz,fm);
        fz=fz/tmp;
        fm=fm/tmp;
        if(fm<0)
        {
            fz=0-fz;
            fm=0-fm;
        }
        stringstream an;
        an<<fz<<"/"<<fm;
        an>>ans;
        return ans;
    }
private:
    int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
            return gcd(b,a%b);
    }
    int lcm(int a,int b)
    {
        return a*b/gcd(a,b);
    }
    int fun(vector<int> v)
    {
        while(v.size()>1)
        {
            int tmp=lcm(v[0],v[1]);
            v.erase(v.begin());
            v.erase(v.begin());
            v.push_back(tmp);
        }
        return v[0];
    }
    int fun2(vector<char> fuhao,vector<int> fenzi,vector<int> fenmu,int f)
    {
        int ans=0;
        for(int i=0;i<fuhao.size();i++)
        {
            int t=f/fenmu[i]*fenzi[i];
            if(fuhao[i]=='-')
            {
                ans-=t;
            }
            else
            {
                ans+=t;
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
    cout<<s.fractionAddition(ss)<<endl;
    return 0;
}
