#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long divd=dividend;
        long long divr=divisor;
        int flag=0;
        if(divd<0)
        {
            flag^=1;
            divd=-divd;
        }
        if(divr<0)
        {
            flag^=1;
            divr=-divr;
        }
        long long ans=0;
        long long a=1;
        while(divd>=divr)
        {
            long long t=divr;
            a=1;
            while(divd>(t<<1))
            {
                t<<=1;
                a<<=1;
            }
            divd-=t;
            ans+=a;
        }
        if(flag)    ans=-ans;
        if(ans>=2147483648)   ans=2147483647;
        return ans;
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    cout<<s.divide(n,m)<<endl;
    return 0;
}
