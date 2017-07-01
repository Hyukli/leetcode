#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n)
        {
            return false;
        }
        while(!(n%2))
        {
            n/=2;
        }
        if(n==1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<(s.isPowerOfTwo(n)?"Yes":"No")<<endl;
    return 0;
}
