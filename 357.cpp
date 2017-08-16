#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> v(101);
        v[0]=1;
        v[1]=10;
        for(int i=2;i<11;i++)
        {
            int k=81;
            for(int j=2;j<i;j++)
            {
                k*=(10-j);
            }
            v[i]=v[i-1]+k;
        }
        if(n<11)
        {
            return v[n];
        }
        else
        {
            return v[10];
        }
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.countNumbersWithUniqueDigits(n)<<endl;
    return 0;
}
