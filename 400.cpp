#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        //1 2 3 4 5 6 7 8 9 | 1 0 1 1 1 2 1 3 ...9 9 | 1 0 0 ...9 9 9
                 //1----9(9)       10----189(2*90)        (3*900)
        vector<long long> num;
        num.push_back(0);
        long long i=1;
        long long j=9;
        while(j<1000000000)
        {
            num.push_back(num[i-1]+i*j);
            i++;
            j*=10;
        }
        int k;
        for(k=0;k<i;k++)
        {
            if(n<=num[k])
            {
                break;
            }
        }
        int t=n-num[k-1];
        int t1=(t-1)/k+1;
        int t2=t%k;
        int ans=1;
        int m=1,f;
        for(i=1;i<k;i++)
        {
            m*=10;
            f=m;
        }
        //cout<<"weishu:"<<k<<endl;
        //cout<<"m:"<<m<<" t1:"<<t1<<endl;
        m+=(t1-1);
        if(t2==0)
        {
            return m%10;
        }
        while(t2>1)
        {
            f/=10;
            t2--;
        }
        return (m/f)%10;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.findNthDigit(n)<<endl;
    return 0;
}
