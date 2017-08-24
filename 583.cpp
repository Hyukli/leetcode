#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1=word1.size(),s2=word2.size();
        vector<vector<int>> dp(s1+1,vector<int>(s2+1));
        for(int i=0;i<=s1;i++)
        {
            for(int j=0;j<=s2;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return word1.size()+word2.size()-2*dp[s1][s2];
    }
};

int main()
{
    Solution s;
    string s1,s2;
    cin>>s1>>s2;
    cout<<s.minDistance(s1,s2)<<endl;
    return 0;
}
