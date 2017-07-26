#include<iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(n&1==1)
            {
                (ans<<=1)+=1;
                n>>=1;
            }
            else
            {
                ans<<=1;
                n>>=1;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.reverseBits(n)<<endl;
    return 0;
}
