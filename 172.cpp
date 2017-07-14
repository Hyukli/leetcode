#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        while(n/5)
        {
            ans+=n/5;
            n/=5;
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.trailingZeroes(n)<<endl;
    return 0;
}
