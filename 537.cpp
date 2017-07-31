#include<iostream>
#include<strstream>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1n,a2n,b1n,b2n,ans1,ans2,flag1,flag2;
        string ans="i";
        a1n=stringtoint(find1(a));
        a2n=stringtoint(find2(a));
        b1n=stringtoint(find1(b));
        b2n=stringtoint(find2(b));
        //cout<<a1n<<" "<<a2n<<" "<<b1n<<" "<<b2n<<endl;
        ans1=a1n*b1n-(a2n*b2n);
        ans2=a1n*b2n+b1n*a2n;
        flag1=ans1<0?1:0;
        flag2=ans2<0?1:0;
        ans1=ans1>=0?ans1:-ans1;
        ans2=ans2>=0?ans2:-ans2;
        if(!ans2)
        {
            ans="0"+ans;
        }
        while(ans2)
        {
            ans=inttostring(ans2%10)+ans;
            ans2/=10;
        }
        if(flag2)
        {
            ans="-"+ans;
        }
        ans="+"+ans;
        if(!ans1)
        {
            ans="0"+ans;
        }
        while(ans1)
        {
            ans=inttostring(ans1%10)+ans;
            ans1/=10;
        }
        if(flag1)
        {
            ans="-"+ans;
        }
        return ans;
    }
private:
    string find1(string s)
    {
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+')
            {
                ans=s.substr(0,i);
            }
        }
        return ans;
    }
    string find2(string s)
    {
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+')
            {
                ans=s.substr(i+1,s.size()-i-2);
            }
        }
        //cout<<ans<<endl;
        return ans;
    }
    int stringtoint(string ans)
    {
        int res=0;
        if(ans[0]=='-')
        {
            for(int i=1;i<ans.size();i++)
            {
                res=res*10+(ans[i]-'0');
            }
            res=0-res;
        }
        else
        {
            for(int i=0;i<ans.size();i++)
            {
                res=res*10+(ans[i]-'0');
            }
        }
        return res;
    }
    string inttostring(int n)
    {
        string s=" ";
        s[0]=n+'0';
        return s;
    }
};

class Solution2 {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;
        strstream aa,bb,ans;
        aa<<a;
        bb<<b;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
        return ans.str();
    }
};

int main()
{
    string a,b;
    cin>>a>>b;
    Solution s;
    cout<<s.complexNumberMultiply(a,b)<<endl;
    return 0;
}
