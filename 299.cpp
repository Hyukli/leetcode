#include<iostream>
using namespace std;

string to_string(int n)
{
    string s="";
    while(n)
    {
        char c=(n%10+'0');
        n/=10;
        s=c+s;
    }
    return s;
}

class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        int bn=0,cn=0;
        int a[10]={0};
        int b[10]={0};
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
                cn++;
            }
            else
            {
                a[secret[i]-'0']++;
                b[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++)
        {
            bn+=min(a[i],b[i]);
        }
        string bnn=to_string(bn);
        string cnn=to_string(cn);
        return cnn+"A"+bnn+"B";
    }
};

int main()
{
    Solution s;
    string s1,s2;
    cin>>s1>>s2;
    cout<<s.getHint(s1,s2)<<endl;
    return 0;
}
