#include<iostream>
#include<vector>
using namespace std;

int dp[1005][1005];

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans=0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++)
            {
                dp[i][j]=0;
            }
        }
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                if(A[i]==B[j])
                {
                    dp[i+1][j+1]=dp[i][j]+1;
                    ans=max(ans,dp[i+1][j+1]);
                }
                else
                {
                    dp[i+1][j+1]=0;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int n,m;
    Solution s;
    cin>>n>>m;
    vector<int> v1(n);
    vector<int> v2(m);
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>v2[i];
    }
    cout<<s.findLength(v1,v2)<<endl;
    return 0;
}
