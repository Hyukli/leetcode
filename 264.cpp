#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n);
        v[0]=1;
        int t1=0,t2=0,t3=0;
        for(int i=1;i<n;i++)
        {
            v[i]=min(2*v[t1],min(3*v[t2],5*v[t3]));
            if(v[i]==2*v[t1])   t1++;
            if(v[i]==3*v[t2])   t2++;
            if(v[i]==5*v[t3])   t3++;
        }
        return v[n-1];
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.nthUglyNumber(n)<<endl;
    return 0;
}
