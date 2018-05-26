#include<iostream>
#include<vector>
#include<map>
using namespace std;

string to_string(int i)
{
    if(!i)  return "0";
    string ans="";
    while(i)
    {
        char k=i%10+'0';
        ans=(k)+ans;
        i/=10;
    }
    return ans;
}

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)
        {
            return "0";
        }
        long long flag=0;
        if(numerator<0) flag^=1;
        if(denominator<0)   flag^=1;
        long long num=numerator;
        if(num<0) num=-num;
        long long den=denominator;
        if(den<0)   den=-den;
        long long k=num/den;
        string dq=to_string(k);
        if(flag)
        {
            dq="-"+dq;
        }
        long long t=num%den;
        string z="";
        map<long long,long long> m;
        long long i=0;
        long long cha;
        while(t!=0&&m.find(t)==m.end())
        {
            m[t]=i++;
            t*=10;
            long long ad=t/den;
            z+=(ad+'0');
            t%=den;
        }
        if(t==0)
        {
            if(z.size()==0) return dq;
            else
            {
                return dq+"."+z;
            }
        }
        else
        {
            cha=m[t];
            z.insert(cha,"(");
            return dq+"."+z+")";
        }
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    cout<<s.fractionToDecimal(n,m)<<endl;
    return 0;
}
