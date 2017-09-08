#include<iostream>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int re=n;
        int left=1;
        int step=1;
        int head=1;
        while(re>1)
        {
            if(left||re%2==1)
            {
                head+=step;
            }
            re/=2;
            step*=2;
            left^=1;
        }
        return head;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.lastRemaining(n)<<endl;
    return 0;
}
