#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1)
        {
            return 9;
        }
        long left=pow(10,n)-2;
        while(left>0)
        {
            long t=left*pow(10,n);
            long tmp=t+reverse(left);
            for(long i=pow(10,n)-1;i*i>=tmp;i--)
            {
                if(tmp%i==0&&(tmp/i)<pow(10,n)-1)
                {
                    return tmp%1337;
                }
            }
            left--;
        }
    }

    long reverse(long n)
    {
        long ans=0;
        while(n)
        {
            ans=ans*10+n%10;
            n/=10;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.largestPalindrome(n)<<endl;
    return 0;
}
