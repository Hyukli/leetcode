#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n,INT_MAX);
        vector<int> index(primes.size(),0);
        ugly[0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<primes.size();j++)
            {
                ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
            }
            for(int j=0;j<primes.size();j++)
            {
                index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);
            }
        }
        return ugly[n-1];
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.nthSuperUglyNumber(k,v)<<endl;
    return 0;
}
