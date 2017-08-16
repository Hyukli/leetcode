#include<iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int mark=0;
        int ans=1;
        while(n>4)
        {
            n-=3;
            ans*=3;
            mark++;
        }
        if(mark)
        {
            ans*=n;
        }
        else if(n==4)
        {
            ans*=4;
        }
        else if(n==3)
        {
            ans*=2;
        }
        else if(n==2)
        {
            ans*=1;
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.integerBreak(n)<<endl;
    return 0;
}
