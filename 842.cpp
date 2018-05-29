#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        for(int i=1;i<=S.size()/2&&i<=10;i++)
        {
            for(int j=1;j<=(S.size()-i)/2&&j<=10;j++)
            {
                vector<string> v;
                v.push_back(S.substr(0,i));
                v.push_back(S.substr(i,j));
                if(dfs(S.substr(0,i),S.substr(i,j),S.substr(i+j),v))
                {
                    for(int i=0;i<v.size();i++)
                    {
                        ans.push_back(stoi2(v[i]));
                    }
                    return ans;
                }
            }
        }
        return ans;
    }
private:
    long long stoi2(string s)
    {
        long long ans=0;
        for(int i=0;i<s.size();i++)
        {
            ans*=10;
            ans+=(s[i]-'0');
        }
        return ans;
    }

    string to_string(int i)
    {
        string ans="";
        if(i==0)    return "0";
        while(i)
        {
            char c=i%10+'0';
            ans=c+ans;
            i/=10;
        }return ans;
    }

    bool dfs(string s1,string s2,string s3,vector<string> &v)
    {
        //cout<<s1<<" "<<s2<<" "<<s3<<endl;
        if(s1.size()>1&&s1[0]=='0'||s2.size()>1&&s2[0]=='0')   return false;
        long long a1=stoi2(s1);
        long long a2=stoi2(s2);
        if(a1>INT_MAX||a2>INT_MAX)  return false;
        if(s3.size()<=10&&!(s3.size()>1&&s3[0]=='0'))
        {
            long long a3=stoi2(s3);
            if(a3<INT_MAX&&a1+a2==a3)
            {
                v.push_back(s3);
                return true;
            }
        }
        long long a3=a1+a2;
        if(a3>INT_MAX)  return false;
        string ss=to_string(a3);
        if(s3.size()<=ss.size()||s3.substr(0,ss.size())!=ss)    return false;
        v.push_back(ss);
        return dfs(s2,ss,s3.substr(ss.size()),v);
    }

};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    vector<int> v=s.splitIntoFibonacci(ss);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
