#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int kthGrammar(int N, int K)
    {
        if (N==1) return 0;
        int x=kthGrammar(N-1,(K+1)/2);
        if (K%2==1) return x; else return x^1;
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    cout<<s.kthGrammar(n,k)<<endl;
    return 0;
}
