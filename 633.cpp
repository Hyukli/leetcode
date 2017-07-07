#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int n=sqrt(c);
        for(int i=0;i<=n;i++)
        {
            int k=c-i*i;
            int t=sqrt(k);
            if(t*t==k)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<(s.judgeSquareSum(n)?"Yes":"No")<<endl;
    return 0;
}
