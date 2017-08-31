#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.bulbSwitch(n)<<endl;
    return 0;
}
