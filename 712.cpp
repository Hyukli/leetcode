#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dp(1005,vector<int> (1005,0));

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        int m=s1.size();
        int n=s2.size();
        int k=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int sum=0;
        for(int i=0;i<m;i++)
        {
            sum+=s1[i];
        }
        for(int i=0;i<n;i++)
        {
            sum+=s2[i];
        }
        sum-=(dp[m][n]*2);
        return sum;
    }
};

int main()
{
    Solution s;
    string s1,s2;
    cin>>s1>>s2;
    cout<<s.minimumDeleteSum(s1,s2)<<endl;
    return 0;
}
