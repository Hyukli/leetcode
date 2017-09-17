#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int a[105];
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                int f=0;
                for(int j=i-1;j>=0;j--)
                {
                    if(!a[j]&&s[j]=='(')
                    {
                        a[j]=1;
                        f=1;
                        break;
                    }
                }
                if(f==0)
                {
                    for(int j=i-1;j>=0;j--)
                    {
                        if(!a[j]&&s[j]=='*')
                        {
                            a[j]=1;
                            f=1;
                            break;
                        }
                    }
                }
                if(f==0)
                {
                    return false;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!a[i])
            {
                if(s[i]=='(')
                {
                    int w=0;
                    for(int j=i+1;j<n;j++)
                    {
                        if(!a[j]&&s[j]=='*')
                        {
                            a[j]=1;
                            w=1;
                            break;
                        }
                    }
                    if(!w)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution ss;
    string s;
    cin>>s;
    cout<<(ss.checkValidString(s)?"Yes":"No")<<endl;
    return 0;
}
