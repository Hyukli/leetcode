#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int tmp=0;
        int ans=0;
        int k=0;

        for(int i=0;i<A.size();i++)
        {
            if(A[i]>R)
            {
                tmp=0;
                k=0;
            }
            else if(A[i]>=L)
            {
                tmp+=1;
                tmp+=k;
                k=0;
                ans+=tmp;
            }
            else
            {
                k++;
                ans+=tmp;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int l,r,n;
    cin>>n>>l>>r;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.numSubarrayBoundedMax(v,l,r)<<endl;
    return 0;
}
