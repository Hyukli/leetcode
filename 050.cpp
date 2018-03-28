#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x==1)
        {
            return x;
        }
        else if(x==-1)
        {
            if(n%2==0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if(n==1)
        {
            return x;
        }
        else if(n<-1000000)
        {
            return 0.0;
        }
        else if(n==0)
        {
            return 1.0;
        }
        else if(n>1)
        {
            int k=n/2;
            int i=n%2;
            double d=myPow(x,k);
            d*=d;
            if(i==1)
            {
                d*=x;
            }
            return d;
        }
        else
        {
            return 1.0/myPow(x,-n);
        }
    }
};

int main()
{
    Solution s;
    double x;
    int n;
    cin>>x>>n;
    cout<<s.myPow(x,n)<<endl;
    return 0;
}
