#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        int a[52];
        memset(a,0,sizeof(a));
        for(int i=0;i<s.size();i++)
        {
            int tmp=s[i]-'A';
            if(s[i]>'Z')
            {
                tmp-=6;
            }
            if(!a[tmp])
            {
                a[tmp]++;
            }
            else
            {
                ans+=2;
                a[tmp]=0;
            }
        }
        for(int i=0;i<52;i++)
        {
            if(a[i])
            {
                ans++;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<ss.longestPalindrome(s)<<endl;
    return 0;
}
