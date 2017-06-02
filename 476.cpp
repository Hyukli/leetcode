#include<iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        unsigned k=1;
        while(k<=num)
        {
            k<<=1;
        }
        return (k-1)^num;
    }
};

int main()
{
    int num;
    cin>>num;
    Solution s;
    cout<<s.findComplement(num);
    return 0;
}
