#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n=num.size();
        for(int i=1;i<=n/2;i++)
        {
            for(int j=1;j<=(n-i)/2;j++)
            {
                if(judge(num.substr(0,i),num.substr(i,j),num.substr(i+j)))  return true;
            }
        }
        return false;
    }

private:
    string add(string s1,string s2)
    {
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        while(s1.size()<s2.size())  s1+="0";
        while(s1.size()>s2.size())  s2+="0";
        string ans="";
        int t=0;
        for(int i=0;i<s1.size();i++)
        {
            int tmp=t+s1[i]-'0'+s2[i]-'0';
            t=0;
            if(tmp>9)
            {
                tmp-=10;
                t=1;
            }
            ans+=(tmp+'0');
        }
        if(t)   ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }

    bool judge(string s1,string s2,string s3)
    {
        if(s1.size()>1&&s1[0]=='0'||s2.size()>1&&s2[0]=='0')    return false;
        string s=add(s1,s2);
        if(s==s3)   return true;
        if(s.size()>=s3.size()||s3.substr(0,s.size())!=s)   return false;
        return judge(s2,s,s3.substr(s.size()));
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<(s.isAdditiveNumber(ss)?"Yes":"No")<<endl;
    return 0;
}
