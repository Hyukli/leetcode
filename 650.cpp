#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                ans+=i;
                n=n/i;
                i=1;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int minSteps(int n) {
        int dp[1003];
        dp[1]=0;
        for(int i=2;i<=n;i++)
        {
            dp[i]=i;
            for(int j=i-1;j>1;j--)
            {
                if(i%j==0)
                {
                    dp[i]=dp[j]+(i/j);
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.minSteps(n)<<endl;
    return 0;
}
