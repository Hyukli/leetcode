#include<iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if(num==0)
        {
            return 0;
        }
        num%=9;
        if(num==0)
        {
            num=9;
        }
        return num;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.addDigits(n)<<endl;
    return 0;
}
