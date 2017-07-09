#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a[1000];
        a[0]=1;
        a[1]=1;
        for(int i=2;i<1000;i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
        return a[n];
    }
};

int main()
{
    int n;
    Solution s;
    cin>>n;
    cout<<s.climbStairs(n)<<endl;
}
