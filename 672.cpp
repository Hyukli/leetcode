#include<iostream>
using namespace std;

class Solution {
public:
    int flipLights(int n, int m) {
        if(m==0||n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return 2;
        }
        else if(n==2)
        {
            if(m==1)
            {
                return 3;
            }
            else
            {
                return 4;
            }
        }
        else
        {
            if(m==1)
            {
                return 4;
            }
            if(m==2)
            {
                return 7;
            }
            else
            {
                return 8;
            }
        }
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    cout<<s.flipLights(n,m)<<endl;
    return 0;
}
