#include<iostream>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[103][103];
        for(int i=s.size()-1;i>=0;i--)
        {
            dp[i][i]=1;
            for(int j=i+1;j<s.size();j++)
            {
                if(s[i]==s[j])
                {
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.longestPalindromeSubseq(ss)<<endl;
    return 0;
}
