#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n=A.size();
        int sum=0;
        for(auto a:A)
        {
            sum+=a;
        }
        int k=0;
        for(int i=0;i<n;i++)
        {
            k+=A[i]*i;
        }
        int ma=k;
        int tmp=k;
        for(int i=n-1;i>=0;i--)
        {
            tmp+=(sum-A[i]*n);
            ma=max(ma,tmp);
        }
        return ma;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.maxRotateFunction(v)<<endl;
    return 0;
}
