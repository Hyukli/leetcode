#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n=A.size();
        vector<int> v1(n,0);
        vector<int> v2(n,0);
        for(int i=1;i<n;i++)
        {
            if(A[i]>A[i-1])
            {
                v1[i]=v1[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(A[i]>A[i+1])
            {
                v2[i]=v2[i+1]+1;
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans=max(ans,(v1[i]&&v2[i])?v1[i]+v2[i]+1:0);
        }
        return ans;
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
    cout<<s.longestMountain(v)<<endl;
    return 0;
}
