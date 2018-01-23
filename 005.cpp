#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string sa="";
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int k=-1;
            for(int j=0;i-j>=0&&i+j<n;j++)
            {
                if(s[i-j]==s[i+j])
                {
                    k+=2;
                    if(k>ans)
                    {
                        ans=k;
                        sa=s.substr(i-j,2*j+1);
                    }
                }
                else
                {
                    break;
                }
            }
        }
        for(int i=0;i<n-1;i++)
        {
            int k=0;
            for(int j=0;i-j>=0&&i+1+j<n;j++)
            {
                if(s[i-j]==s[i+1+j])
                {
                    k+=2;
                    if(k>ans)
                    {
                        ans=k;
                        sa=s.substr(i-j,2*(j+1));
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return sa;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.longestPalindrome(ss)<<endl;
    return 0;
}
