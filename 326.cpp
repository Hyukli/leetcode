#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (1162261467 % n == 0);
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<(s.isPowerOfThree(n)?"Yes":"No")<<endl;
    return 0;
}
