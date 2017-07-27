#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long r=x;
        while(r*r>x)
        {
            r=(r+x/r)/2;
        }
        return r;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.mySqrt(n)<<endl;
    return 0;
}
