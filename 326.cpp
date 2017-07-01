#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (1162261467 % n == 0);
    }
};

class Solution2 {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1)==0;//因为没有log3（）这样的函数，只能利用公式转化。
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
