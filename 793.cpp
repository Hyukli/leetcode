#include<iostream> 
#include<vector>
using namespace std;

class Solution {
public:
    int preimageSizeFZF(int K) {
        return (int)(count(K)-count(K-1));
    }
    long long count(int n)
    {
        long long low=-1;
        long long high=5000000000;
        while(high-low>1)
        {
            long long h=high+low>>1;
            long long s=0;
            for(long long k=h/5;k>0;k/=5)
            {
                s+=k;
            }
            if(s<=n)
            {
                low=h;
            }
            else
            {
                high=h;
            }
        }
        return low+1;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.preimageSizeFZF(n)<<endl;
    return 0;
}
