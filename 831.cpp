#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string maskPII(string S) {
        string ans="";
        bool flag=0;
        int k=0;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='@')
            {
                flag=1;
                k=i;
                break;
            }
        }
        if(flag)
        {
            ans+=fun(S[0]);
            ans+="*****";
            ans+=fun(S[k-1]);
            for(int i=k;i<S.size();i++)
            {
                ans+=fun(S[i]);
            }
        }
        else
        {
            vector<int> v;
            for(int i=0;i<S.size();i++)
            {
                if(S[i]>='0'&&S[i]<='9')
                {
                    v.push_back(S[i]-'0');
                }
            }
            if(v.size()==10)
            {
                ans+="***-***-";
                for(int i=6;i<10;i++)
                {
                    ans+=(v[i]+'0');
                }
            }
            else
            {
                ans+="+";
                for(int l=10;l<v.size();l++)
                {
                    ans+="*";
                }
                ans+="-***-***-";
                for(int l=v.size()-4;l<v.size();l++)
                {
                    ans+=(v[l]+'0');
                }
            }
        }
        return ans;
    }
private:
    char fun(char c)
    {
        if(c>='A'&&c<='Z')
        {
            c=c-'A'+'a';
        }
        return c;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.maskPII(ss)<<endl;
    return 0;
}
