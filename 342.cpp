#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(fmod(log10(num)/log10(4),1)==0)
        {
            return true;
        }
        return false;
    }
};

int main() {
	int n;
	cin>>n;
	Solution s;
	cout<<(s.isPowerOfFour(n)?"Yes":"No")<<endl;
	return 0;
}
