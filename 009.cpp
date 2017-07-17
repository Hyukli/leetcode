#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int n) {
        if(n<0)
        {
            return false;
        }
        long long div=1;
        while(n/div)
        {
            div*=10;
        }
        div/=10;
        while(n)
        {
            int l=n/div;
            int r=n%10;
            if(l!=r)
            {
                return false;
            }
            n%=div;
            n/=10;
            div/=100;
        }
        return true;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<(s.isPalindrome(n)?"Yes":"No")<<endl;
    return 0;
}
