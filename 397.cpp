#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if(n==1)
        {
            return 0;
        }
        if(n==3)
        {
            return 2;
        }
        if (n == INT_MAX)
            return 32;
        if(n%2==1)
        {
            if((n+1)%4==0)
            {
                return 1+integerReplacement(n+1);
            }
            else
            {
                return 1+integerReplacement(n-1);
            }
        }
        else
        {
            return 1+integerReplacement(n/2);
        }
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.integerReplacement(n)<<endl;
    return 0;
}
