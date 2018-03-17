#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& A, int target) {
        int n=A.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(A[m]==target)    return m;
            if(A[m]>=A[l])
            {
                if(A[l]<=target&&target<=A[m])  r=m-1;
                else    l=m+1;
            }
            else
            {
                if(target>=A[l]||target<=A[m])  r=m-1;
                else    l=m+1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.search(v,t)<<endl;
    return 0;
}
