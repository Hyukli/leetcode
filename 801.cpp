#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int dp[1003][2];
        memset(dp,100,sizeof(dp));
        dp[0][0]=0;
        dp[0][1]=1;
        for(int i=1;i<n;i++)
        {
            if(A[i]>A[i-1]&&B[i]>B[i-1])
            {
                dp[i][0]=min(dp[i][0],dp[i-1][0]);
                dp[i][1]=min(dp[i][1],dp[i-1][1]+1);
            }
            if(A[i]>B[i-1]&&B[i]>A[i-1])
            {
                dp[i][0]=min(dp[i][0],dp[i-1][1]);
                dp[i][1]=min(dp[i][1],dp[i-1][0]+1);
            }
        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v1(n);
    vector<int> v2(n);
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>v2[i];
    }
    cout<<s.minSwap(v1,v2)<<endl;
    return 0;
}
