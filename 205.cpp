#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return issimple(s,t)&&issimple(t,s);
    }
private:
    bool issimple(string s,string t)
    {
        int ss=s.size();
        int a[100000];
        memset(a,0,sizeof(a));
        for(int i=0;i<ss;i++)
        {
            if(!a[i])
            {
                a[i]=1;
                char c1=s[i];
                char c2=t[i];
                for(int j=i+1;j<ss;j++)
                {
                    if(s[j]==c1)
                    {
                        if(t[j]!=c2)
                        {
                            return false;
                        }
                        a[j]=1;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sw;
    string s,t;
    cin>>s>>t;
    cout<<(sw.isIsomorphic(s,t)?"Yes":"No")<<endl;
    return 0;
}
