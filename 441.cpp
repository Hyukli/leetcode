#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0)
        {
            return 0;
        }
        long long n2=n;
        long long nn=2*n2;
        long long k=sqrt(nn);
        long long t=(1+k)*k/2;
        if(n<t)
        {
            return k-1;
        }
        else
        {
            return k;
        }
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.arrangeCoins(n)<<endl;
    return 0;
}
