#include<iostream>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        string ss=s;
        int i,j;
        int n=s.size();
        int flag=0;
        for( i=0,j=n-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return true;
        }
        flag=0;
        s=s.substr(0,i)+ss.substr(i+1);
        //cout<<s<<endl;
        for(int i=0,j=n-2;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return true;
        }
        flag=0;
        s=ss.substr(0,j)+ss.substr(j+1);
        //cout<<s<<endl;
        for(int i=0,j=n-2;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<ss.validPalindrome(s)<<endl;
    return 0;
}
