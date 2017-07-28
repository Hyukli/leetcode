#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n==1||n==0)
        {
            return 0;
        }
        vector<int> a(n,0);
        int ans=0;
        a[0]=a[1]=1;
        for(int i=2;i*i<n;i++)
        {
            for(int j=i;i*j<n;j++)
            {
                a[i*j]=1;
            }
        }
        return count(a.begin(),a.end(),0);
    }
};

int main()
{
    int n;
    Solution s;
    cin>>n;
    cout<<s.countPrimes(n)<<endl;
    return 0;
}
