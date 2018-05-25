#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> v(n+1,0);
        if(s[0]=='0')   return 0;
        else v[0]=v[1]=1;
        for(int i=1;i<s.size();i++)
        {
            if(judge(s[i])) v[i+1]+=v[i];
            if(judge2(s.substr(i-1,2)))  v[i+1]+=v[i-1];
        }
        return v[n];
    }
private:
    bool judge(char c)  {if(c>'0'&&c<='9')   return true;    return false;}
    bool judge2(string s)
    {
        if(s[0]=='0')   return false;
        int tmp=0;
        for(int i=0;i<2;i++)
        {
            tmp*=10;
            tmp+=s[i]-'0';
        }
        if(tmp>=10&&tmp<=26)    return true;
        return false;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.numDecodings(ss)<<endl;
    return 0;
}
