#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z)   return false;
        if(x==z||y==z||x+y==z)  return true;
        return z%GCD(x,y)==0;
    }

    int GCD(int a,int b)
    {
        while(b!=0)
        {
            int tmp=b;
            b=a%b;
            a=tmp;
        }
        return a;
    }
};

int main()
{
    Solution s;
    int x,y,z;
    cin>>x>>y>>z;
    cout<<(s.canMeasureWater(x,y,z)?"Yes":"No")<<endl;
    return 0;
}
