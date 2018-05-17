#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        const int M=1e9+7;
        int n=A.size();
        sort(A.begin(),A.end());
        map<int,long long> m;
        vector<long long> dp(n,1);
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            m[A[i]]=i;
            for(int j=0;j<i;j++)
            {
                if(A[i]%A[j]==0&&m.find(A[i]/A[j])!=m.end())
                {
                    int k=A[i]/A[j];
                    dp[i]+=dp[j]*dp[m[k]];
                    dp[i]%=M;
                }
            }
            ans+=dp[i];
            ans%=M;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.numFactoredBinaryTrees(v)<<endl;
    return 0;
}
